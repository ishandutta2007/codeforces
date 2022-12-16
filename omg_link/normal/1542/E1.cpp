#include <stdio.h>
#include <string.h>
#define MN 500
typedef long long ll;

int n,mod;
int _f[2][MN*(MN+1)+10][3];
int (*f[2])[3]={&_f[0][MN*(MN+1)/2+5],&_f[1][MN*(MN+1)/2+5]};

int any(int f[3]){
	ll tot = 0;
	for(int i=0;i<3;i++)
		tot += f[i];
	return tot%mod;
}

int main(){
	scanf("%d%d",&n,&mod);
	f[0][0][0] = 1;
	for(int i=1;i<=n;i++){
		int S = i&1;
		int T = S^1;
		int max = i*(i-1)/2;
		for(int j=-max;j<=max;j++){
			for(int k=0;k<3;k++){
				f[S][j][k] = (ll)i*f[T][j][k]%mod;
			}
		}
		if(i!=1){
			ll tot=0,ttot=0;
			for(int j=max;j>=-max;j--){
				tot += any(f[T][j-(i-1)]);
				ttot += tot;
				f[S][j][1] = (f[S][j][1]+ttot)%mod;
				int tmp = any(f[T][j-1]);
				tot -= tmp;
				ttot -= (ll)(i-1)*tmp;
			}
			tot = 0;
			ttot = 0;
			for(int j=-max;j<=max;j++){
				tot  += any(f[T][j+(i-1)]);
				ttot += tot;
				f[S][j][2] = (f[S][j][2]+ttot)%mod;
				int tmp = any(f[T][j+1]);
				tot -= tmp;
				ttot -= (ll)(i-1)*tmp;
			}
		}
	}
	//f[n][+][2];
	int max = n*(n-1)/2;
	int ans = 0;
	for(int j=1;j<=max;j++){
		ans = (ans+f[n&1][j][2])%mod;
	}
	ans = (ans+mod)%mod;
	printf("%d\n",ans);
}