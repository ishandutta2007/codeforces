#include <bits/stdc++.h>

using namespace std;
long long n, m, mod, ans, t[100002];
map<int, int> phi2;
long long po(long long a, long long b, long long mod) {
    long long ans=1, spec=0;
    while (b) {
        if (b%2) {
            ans*=a;
            if (ans>=mod) {
                spec=1;
                ans%=mod;
            }
        }
        a*=a;
        if (a>=mod) {
            a%=mod, a+=mod;
        }
        b/=2;
    }
    if (spec) {
        ans+=mod;
    }
    return ans;
}

int phi(int n) {
    if (!phi2[n]) {
        int result = n;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                while (n % i == 0)
                    n /= i;
                result -= result / i;
            }
        }
        if (n > 1) {
            result -= result / n;
        }
        phi2[n]=result;
    }
    return phi2[n];
}




long long solve(int l, int r, long long mod) {
    //cout << "solve " << l << " " << r << " " << mod << "\n";
    if (l==r) {
        return t[l];
    }
    if (mod==1) {
        return 1;
    }
    long long s=phi(mod);
    return (po(t[l], solve(l+1, r, s), mod));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> mod;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    cin >> m;
    for (int i=1; i<=m; i++) {
        int l, r;
        cin >> l >> r;
        //cout << "valasz: ";
        cout << solve(l, r, mod)%mod << "\n";
    }
    return 0;
}
/*
6 19
1 2 2 3 3 3
1
1 6
*/