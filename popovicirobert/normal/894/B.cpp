#include <bits/stdc++.h>
#define lsb(x)
#define ll long long

using namespace std;

const int MOD = (int) 1e9 + 7;

inline int lgput(int a, ll b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1)
            ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

int main(){
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    ll n, m;
    int k;
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    if(k == 1) {
        cout << lgput(lgput(2, n - 1), m - 1);
    }
    else {
        if((n + m) % 2 == 0)
            cout << lgput(lgput(2, n - 1), m - 1);
        else
            cout << 0;
    }
    //cin.close();
    //cout.close();
    return 0;
}