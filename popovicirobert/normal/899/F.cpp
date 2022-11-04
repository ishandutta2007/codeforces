#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

string str;

multiset <int> mst[300];
multiset <int> :: iterator it1, it2, aux;

const int MAXN = (int) 2e5;

int aib[MAXN + 1];

inline void update(int pos, int n) {
    for(int i = pos; i <= n; i += lsb(i))
        aib[i]++;
}

inline int query(int pos) {
    int ans = 0;
    for(int i = pos; i > 0; i -= lsb(i))
        ans += aib[i];
    return ans;
}

char sol[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, l, r;
    char ch;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    cin >> str;
    str = " " + str;
    for(i = 1; i <= n; i++) {
        mst[str[i]].insert(i);
    }
    while(m > 0) {
        m--;
        cin >> l >> r >> ch;
        int rez1 = 0, rez2 = 0;
        for(int pas = 1 << 17; pas; pas >>= 1) {
            if(rez1 + pas <= n && rez1 + pas - query(rez1 + pas) < l)
                rez1 += pas;
            if(rez2 + pas <= n && rez2 + pas - query(rez2 + pas) < r)
                rez2 += pas;
        }
        rez1++;
        rez2++;
        aux = it1 = mst[ch].lower_bound(rez1);
        it2 = mst[ch].upper_bound(rez2);
        while(it1 != it2) {
            update(*it1, n);
            it1++;
        }
        mst[ch].erase(aux, it2);
    }
    for(i = 0; i < 300; i++) {
        for(it1 = mst[i].begin(); it1 != mst[i].end(); it1++)
            sol[*it1] = i;
    }
    for(i = 1; i <= n; i++) {
        if(sol[i] > 0)
            cout << sol[i];
    }
    //cin.close();
    //cout.close();
    return 0;
}