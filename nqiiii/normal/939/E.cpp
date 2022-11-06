#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=500000;
ll s[maxn+10]; int cnt,q; ll a[maxn+10];
double now;
int main(){
	scanf("%d",&q);
	for(;q--;){
		int x; ll v;
		scanf("%d",&x);
		if(x==1){
			scanf("%lld",&v); int l=0,r=cnt;
			for(;l!=r;){
				int mid=(l+r+1)/2;
				if(a[mid]*(mid+1)<v+s[mid]) l=mid; else r=mid-1;
			}
			now=max(now,v-1.0*(v+s[l])/(l+1)); a[++cnt]=v; s[cnt]=s[cnt-1]+a[cnt];
		}else printf("%.10lf\n",now);
	}
}