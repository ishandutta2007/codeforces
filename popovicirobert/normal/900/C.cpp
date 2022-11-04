#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MAXN = (int) 1e5;

int v[MAXN + 1], mx[MAXN + 1];
int aib[MAXN + 1];

inline void update(int pos) {
    for(int i = pos; i <= MAXN; i += lsb(i))
        aib[i]++;
}

inline int query(int pos) {
    int ans = 0;
    for(int i = pos; i > 0; i -= lsb(i))
        ans += aib[i];
    return ans;
}

int fr[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
        mx[i] = max(mx[i - 1], v[i]);
        if(query(MAXN) - query(v[i]) == 1)
            fr[mx[i]]++;
        if(query(MAXN) - query(v[i]) == 0)
            fr[v[i]]--;
        update(v[i]);
    }
    int ans = -2, pos;
    for(i = 1; i <= n; i++) {
        if(ans < fr[i]) {
            ans = fr[i];
            pos = i;
        }
    }
    cout << pos;
    //cin.close();
    //cout.close();
    return 0;
}