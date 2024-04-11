#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, p, t[c], fib[c], fib2[c], ans, mod=1e9+7;
set<long long> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> p;
    //n=100, p=100;
    fib[0]=1, fib2[0]=1, fib[1]=1, fib2[1]=2;
    for (int i=2; i<=p; i++) {
        fib[i]=(fib[i-1]+fib[i-2])%mod;
        fib2[i]=(fib2[i-1]+fib[i])%mod;
    }

    for (int i=1; i<=n; i++) {
        cin >> t[i];
        //t[i]=i;
    }
    sort(t+1, t+n+1);

    for (int i=1; i<=n; i++) {
        long long x=t[i], y=p-64+__builtin_clzll(x);
        if (y<0) {
            continue;
        }
        bool jo=1;
        while (x>0 && x%4!=2) {
            if (x%2) {
                x/=2;
            } else {
                x/=4;
            }
            if (s.find(x)!=s.end()) {
                jo=0;
            }
        }
        if (jo) {
            //cout << "fontos " << t[i] << "\n";
            s.insert(t[i]);
            ans=(ans+fib2[y])%mod;
        }
    }
    cout << ans << "\n";
    return 0;
}