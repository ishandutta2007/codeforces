#include <bits/stdc++.h>

using namespace std;
long long n, m, k;
long long mod=998244353;
long long ans=1;
long long pr[2001];
bool v[2001];
vector<int> prim;
long long alatt(long long a, long long b)
{
    b=min(b, a-b);
    for (int i=1;i<=b; i++) {
        int x=i;
        for (int i=0; x>1; i++) {
            while(x%prim[i]==0) {
                pr[i]--;
                x/=prim[i];
            }
        }
    }
    for (int i=a-b+1; i<=a; i++) {
        int x=i;
        for (int i=0; x>1; i++) {
            while(x%prim[i]==0) {
                pr[i]++;
                x/=prim[i];
            }
        }
    }
    long long q=1;
    for (int i=0; i<=2000; i++) {
        if (pr[i]>=0) {
            for (int j=1; j<=pr[i]; j++) {
                q*=prim[i];
                q%=mod;
            }
        }
    }
    return q;
}
int main()
{
    cin >> n >> m >> k;
    for (int i=2; i<=n; i++) {
        if (!v[i]) {
            prim.push_back(i);
            for (int j=i; j<=2000; j+=i) {
                v[i]=true;
            }
        }
    }
    ans*=alatt(n-1, k);
    ans*=m;
    ans%=mod;
    for (int i=1; i<=k; i++) {
        ans*=(m-1);
        ans%=mod;
    }
    cout << ans << endl;
    return 0;
}