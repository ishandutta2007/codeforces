#include <bits/stdc++.h>

using namespace std;
const int c=21, mod=31607, e=10000, inv=3973;
int n, n2, t2[c][c], t[c][c], sum, ert[c][1<<c], prod[1<<c];
int lsb(int a) {
    return (a & (-a));
}
int solve() {
    int ans=0, u=1;

    prod[0]=1;
    for (int j=0; j<n; j++) {
        int s=(1<<j);
        prod[s]=1;
        for (int i=0; i<n; i++) {
            prod[s]=prod[s]*t[i][j]%mod;
        }
    }
    for (int i=1; i<n2; i++) {
        if (__builtin_popcount(i)>1) {
            int el=lsb(i);
            prod[i]=prod[el]*prod[i-el]%mod;
        }
    }
    for (int i=0; i<n; i++) {
        ert[i][0]=1;
        for (int j=1; j<n2; j++) {
            int el=j-lsb(j), dif=__builtin_ctz(j-el);
            ert[i][j]=ert[i][el]*t[i][dif]%mod;
        }
    }
    for (int i=0; i<n; i++) {
        u=u*(1+mod-ert[i][n2-1])%mod;
    }
    ans=(mod+1-u)%mod;
    for (int mask=1; mask<n2; mask++) {
        u=1;
        for (int i=0; i<n; i++) {
            u=u*(1+mod-ert[i][n2-1-mask])%mod;
        }
        int db=__builtin_popcount(mask), ert=prod[mask]*u%mod;
        if (db%2==0) {
            ert=-ert+mod;
        }
        ans=(ans+ert)%mod;
    }

    return (mod+1-ans)%mod;
}
int main()
{
    cin >> n;
    n2=(1<<n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> t2[i][j];
            t2[i][j]*=inv;
            t2[i][j]%=mod;
            t[i][j]=t2[i][j];
        }
    }
    for (int s=0; s<4; s++) {
        int mul=1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                t[i][j]=t2[i][j];
                if (s%2 && i==j || s>=2 && i+j==n-1) {
                    mul*=t2[i][j], mul%=mod;
                    t[i][j]=1;
                }
            }
        }
        int add=solve()*mul%mod;
        if (s==0 || s==3) {
            sum+=add;
        } else {
            sum-=add;
            sum+=mod;
        }
    }
    cout << (1-sum+10*mod)%mod << "\n";
    return 0;
}