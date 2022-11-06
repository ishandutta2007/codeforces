#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
const int N=405;
int n,m, t;
LL f[N][N<<1], fac[N];
LL r,ret, mod;
LL ksm(LL u,LL v){
    ret=1;
    while(v){
        if(v&1)ret=ret*u%mod;
        u=u*u%mod;v>>=1;
    }
    return ret;
}
int main(){
	cin >> t >> mod;
    n = 400;
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % mod;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j) {
			if (j == 1) f[i][j] = fac[i];
			else {
				for (int k = 0; k <= i - j; ++k) {
					f[i][j] += fac[k + 1] * f[i - k - 1][j - 1];
					f[i][j] %= mod;
				}
			}
		}
	m=n*2;
    for(int i=1;i<=n;++i){
        f[i][n+i]=1;
    }
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;j++)
        if(f[j][i]){
            for(int k=1;k<=m;k++)
            swap(f[i][k],f[j][k]);
            break;
        }
        if(!f[i][i]){puts("No Solution");return 0;}
        r=ksm(f[i][i],mod-2);
        for(int j=i;j<=m;++j)
        f[i][j]=f[i][j]*r%mod;
        for(int j=1;j<=n;++j)
        if(j!=i){
            r=f[j][i];
            for(int k=i;k<=m;++k)
            f[j][k]=(f[j][k]-r*f[i][k]%mod+mod)%mod;
        }
    }
	while (t--) {
		int x; scanf("%d", &x);
		if (x == 2) cout << 2 << endl;
		else if (x % 2 == 1) cout << (-f[x][n + 1] + 2 + mod) % mod << endl;
		else cout << (-f[x][n + 1] - 2 + mod + mod) % mod << endl;
	}
}