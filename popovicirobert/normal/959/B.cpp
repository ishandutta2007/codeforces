#include <bits/stdc++.h>
#define ll long long

using namespace std;

string str;
map <string, int> mp;


const int MAXN = (int) 1e5;

int sef[MAXN + 1];
int v[MAXN + 1];

int myfind(int x) {
    if(sef[x] == 0)
        return x;
    return sef[x] = myfind(sef[x]);
}

inline void myunion(int x, int y) {
    if(v[myfind(x)] < v[myfind(y)])
        swap(x, y);
    if(myfind(x) != myfind(y))
        sef[myfind(x)] = myfind(y);
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, k, nr, a, b;
    ios::sync_with_stdio(false);
    cin >> n >> k >> m;
    for(i = 1; i <= n; i++) {
        cin >> str;
        mp[str] = i;
    }
    for(i = 1; i <= n; i++) {
        cin >> v[i];
    }
    while(k > 0) {
        k--;
        cin >> nr >> a;
        while(nr > 1) {
            nr--;
            cin >> b;
            myunion(a, b);
        }
    }
    ll ans = 0;
    for(i = 1; i <= m; i++) {
        cin >> str;
        ans += v[myfind(mp[str])];
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}