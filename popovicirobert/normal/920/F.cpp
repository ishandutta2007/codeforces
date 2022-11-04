#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 113

using namespace std;

const int MAXN = (int) 3e5;
const int MAXVAL = (int) 1e6;

int v[MAXN + 1];
int divi[MAXVAL + 1];
int dp[MAXVAL + 1];

inline void prec() {
    for(int i = 1; i <= MAXVAL; i++) {
        for(int j = i; j <= MAXVAL; j += i)
            divi[j]++;
    }
}

ll aib[MAXN + 1];

inline void update(int pos, int n, int val) {
    for(int i = pos; i <= n; i += lsb(i))
        aib[i] += val;
}

inline ll query(int pos) {
    ll ans = 0;
    for(int i = pos; i > 0; i -= lsb(i))
        ans += aib[i];
    return ans;
}

int sef[MAXN + 1];

int myfind(int x) {
    if(sef[x] == 0)
        return x;
    return sef[x] = myfind(sef[x]);
}

inline void myunion(int x, int y) {
    if(myfind(x) != myfind(y))
        sef[myfind(x)] = myfind(y);
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    //ios::sync_with_stdio(false);
    scanf("%d%d" ,&n,&m);
    for(i = 1; i <= n; i++) {
        scanf("%d" ,&v[i]);
        if(v[i] <= 2 && i < n)
            myunion(i, i + 1);
        update(i, n, v[i]);
    }
    prec();
    while(m > 0) {
        m--;
        int t, l, r;
        scanf("%d%d%d" ,&t,&l,&r);
        if(t == 1) {
            int pos = myfind(l);
            while(pos <= r) {
                int aux = v[pos];
                v[pos] = divi[v[pos]];
                update(pos, n, v[pos] - aux);
                if(v[pos] <= 2) {
                    if(pos != n)
                        myunion(pos, pos + 1);
                }
                if(pos == n)
                    pos++;
                else
                    pos = myfind(pos + 1);
            }
        }
        else {
            printf("%I64d\n" ,query(r) - query(l - 1));
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}