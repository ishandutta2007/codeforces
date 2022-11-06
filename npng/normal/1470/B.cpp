#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=300000;
const int Maxv=1000000;
const int Maxp=1000;
int n;
int a[Maxn+5];
bool np[Maxp+5];
int p[Maxp+5],p_len;
int f[Maxv+5];
void init(){
	np[0]=np[1]=1;
	for(int i=2;i<=Maxp;i++){
		if(!np[i]){
			p[++p_len]=i;
			for(int j=i*i;j<=Maxp;j+=i){
				np[j]=1;
			}
		}
	}
	for(int i=1;i<=Maxv;i++){
		if(f[i]==0){
			f[i]=i;
		}
		for(int j=1;j<=p_len&&1ll*i*p[j]*p[j]<=Maxv;j++){
			f[i*p[j]*p[j]]=f[i];
		}
	}
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]=f[a[i]];
	}
	sort(a+1,a+1+n);
	int ans_1=0,ans_2=0;
	int num_0=0;
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(j<=n&&a[j]==a[i]){
			j++;
		}
		j--;
		ans_1=max(ans_1,j-i+1);
		if(!((j-i+1)&1)||a[i]==1){
			num_0+=j-i+1;
		}
	}
	ans_2=max(ans_1,num_0);
	int q;
	scanf("%d",&q);
	while(q--){
		ll w;
		scanf("%lld",&w);
		if(w==0){
			printf("%d\n",ans_1);
		}
		else{
			printf("%d\n",ans_2);
		}
	}
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}