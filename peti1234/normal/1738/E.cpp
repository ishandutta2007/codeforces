#include <bits/stdc++.h>

using namespace std;


/*
c meg mod erteket be kell allitani
calc n utan n-ig tud faktorialis, inverz es a alatt b-t szamolni
*/


const int c=500005;
long long mod=998244353;



long long fakt[c], inv[c];
long long po(long long a, long long p) {
    long long ans=1;
    while (p) {
        if (p%2) {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        p/=2;
    }
    return ans;
}
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        p/=2;
    }
    return ans;
}

long long alatt(long long a, long long b) {
    if (a<b || b<0) return 0;
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
long long alatt2(long long a, long long b) {
    if (a<b || b<0) return 0;
    long long ans=1;
    for (int i=1; i<=b; i++) {
        ans=ans*(a+1-i)%mod;
    }
    return ans*inv[b]%mod;
}
void calc(int a) {
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<=a; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }
}

long long t[c], n;

void solve() {
    cin >> n;
    long long ans=1, s=0;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        s+=t[i];
    }
    long long pref=t[1], suf=t[n], bal=1, jobb=n;
    if (n==1) {
        cout << 1 << "\n";
        return;
    }
    while (true) {
        //cout << "proba " << bal << " " << jobb << " " << pref << " " << suf << "\n";
        if (pref+suf>s) {
            break;
        }
        if (pref+suf==s) {
            if (pref==suf) {
                ans=ans*po(2, jobb-bal)%mod;
            }
            break;
        }
        if (pref==suf) {
            //cout << "fontos " << bal << " " << jobb << "\n";
            long long a=1, b=1;
            while (t[bal+1]==0) {
                bal++;
                a++;
            }
            while (t[jobb-1]==0) {
                jobb--;
                b++;
            }
            long long sum=0;
            for (long long i=0; i<=min(a, b); i++) {
                sum=(sum+alatt(a, i)*alatt(b, i))%mod;
            }
            ans=(ans*sum)%mod;

            bal++;
            pref+=t[bal];
            jobb--;
            suf+=t[jobb];
        }
        if (pref>suf) {
            jobb--, suf+=t[jobb];
        }
        if (suf>pref) {
            bal++, pref+=t[bal];
        }
    }
    //cout << "valasz............ ";
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    calc(200005);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
1
5
1 2 3 2 1
*/