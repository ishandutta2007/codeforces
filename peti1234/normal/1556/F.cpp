#include <bits/stdc++.h>

using namespace std;
const int c=14, c2=(1<<c), c3=4800000;
long long mod=1e9+7;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans*=a;
            ans%=mod;
        }
        a*=a;
        a%=mod;
        p/=2;
    }
    return ans;
}
long long mul(long long a, long long b) {
    return a*b%mod;
}
long long add(long long a, long long b) {
    return (a+b>=mod ? a+b-mod : a+b);
}
long long n, n2, t[c], b[c][c], d[c][c2], d2[c3], dp[c2], ans;
long long ut[c2], po2[c], po3[c], mask2[c2], mask3[c2];

int valt(int a, int b) {
    return mask3[a]+mask2[b];
}
int main()
{
    cin >> n;
    n2=(1<<n);

    po2[0]=1, po3[0]=1;
    for (int i=1; i<n; i++) {
        po2[i]=po2[i-1]*2, po3[i]=po3[i-1]*3;
    }
    for (int i=1; i<n2; i++) {
        ut[i]=__builtin_ctz(i);
        int s=i-(1<<ut[i]);
        mask2[i]=mask2[s]+po3[ut[i]];
        mask3[i]=2*mask2[i];
    }



    for (int i=0; i<n; i++) {
        cin >> t[i];
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            b[i][j]=t[i]*(oszt(t[i]+t[j])%mod)%mod;
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n2; j++) {
            d[i][j]=1;
            for (int k=0; k<n; k++) {
                if (j & (1<<k)) {
                    d[i][j]=mul(d[i][j], b[i][k]);
                }
            }
        }
    }
    for (int i=1; i<n2; i++) {
        int rem=n2-1-i;
        for (int j=rem; ; j=(j-1)&rem) {
            int fix=valt(0, j);
            d2[fix]=1;
            int id=valt(i, j), el=valt(i-(1<<ut[i]), j);
            d2[id]=mul(d2[el], d[ut[i]][j]);

            if (j==0) {
                break;
            }
        }
    }


    for (int fix=0; fix<n; fix++) {

        for (int i=0; i<n2; i++) {
            if (!(i & po2[fix])) {
                continue;
            }
            dp[i]=1;
            for (int j=i&(i-1); j>0; j=(j-1)&i) {
                if (!(j & po2[fix])) {
                    continue;
                }
                dp[i]=(dp[i]-dp[j]*d2[valt(i-j, j)]%mod+mod)%mod;
            }
        }
        ans+=dp[n2-1];
    }
    cout << ans%mod << "\n";




    return 0;
}
/*
5
0 0 0 0 1
*/