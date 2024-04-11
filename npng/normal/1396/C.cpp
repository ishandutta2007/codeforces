#include <cstdio>
#include <algorithm>
using namespace std;
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
typedef long long ll;
const int Maxn=1000000;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
int n;
int r_1,r_2,r_3,d;
int a[Maxn+5];
ll f[Maxn+5][2];
int main(){
	read(n),read(r_1),read(r_2),read(r_3),read(d);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	r_1=min(r_1,r_3);
	f[0][1]=Inf;
	for(int i=1;i<=n;i++){
		f[i][0]=f[i][1]=Inf;
		ll cost_1=1ll*a[i]*r_1+r_3;
		ll cost_2=min(cost_1,min(1ll*a[i]*r_1+r_1+r_1,1ll*r_2+r_1));
		f[i][0]=min(f[i][0],f[i-1][0]+cost_1);
		f[i][1]=min(f[i][1],f[i-1][0]+d+cost_2);
		f[i][0]=min(f[i][0],f[i-1][1]+d+cost_2);
		if(i==n){
			f[i][0]=min(f[i][0],f[i-1][1]+cost_1);
		}
	}
	printf("%lld\n",min(f[n][0],f[n][1]+d)+1ll*d*(n-1));
	return 0;
}