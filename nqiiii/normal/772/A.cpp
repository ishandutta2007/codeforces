#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100000;
int n,p,a[maxn+10],b[maxn+10]; long long tot;
bool check(double v){
	double now=p;
	for(int i=1;i<=n;++i) now-=max(a[i]-b[i]/v,0.0);
	return now>=0;
}
int main(){
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i],&b[i]); tot+=a[i];
	}
	if(p>=tot){
		printf("-1"); return 0;
	}
	double ans=0;
	for(double i=1e18;i>1e-5;i/=2) ans=check(ans+i)?ans+i:ans;
	printf("%.5lf",ans);
}