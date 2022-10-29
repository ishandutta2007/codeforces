#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
using namespace std;
const int N=1e5+9;
int a[N],b[N];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int cnt=0,cnt2=0;
		rep(i,0,n<<1){
			int x,y;
			scanf("%d%d",&x,&y);
			if(!x)a[cnt++]=abs(y);
			else b[cnt2++]=abs(x);
		}
		sort(a,a+n);
		sort(b,b+n);
		double ans=0;
		rep(i,0,n)ans+=sqrt(1ll*a[i]*a[i]+1ll*b[i]*b[i]);
		printf("%.9lf\n",ans);
	}
}