#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long n, t[c], mini;
void solve(long long mod) {
    long long ans=0;
    for (int i=1; i<=n; i++) {
        long long s=mod-t[i]%mod;
        if (t[i]>=mod) s=min(s, t[i]%mod);
        ans+=s;
    }
    mini=min(mini, ans);
}
void fakt(long long a) {
    if (a<2) return;
    for (long long i=2; i*i<=a; i++) {
        if (a%i==0) {
            solve(i);
            while(a%i==0) a/=i;
        }
    }
    if (a!=1) {
        solve(a);
    }
}
int main()
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        mini+=t[i]%2;
    }
    for (int i=1; i<=30; i++) {
        int x=uniform_int_distribution<int>(1, n)(rng);
        long long y=t[x];
        fakt(y-1), fakt(y), fakt(y+1);
    }
    cout << mini << "\n";
    return 0;
}