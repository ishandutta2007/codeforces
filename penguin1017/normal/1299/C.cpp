#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
using namespace std;
const int N=1e6+9;
const ll mod=998244353;
const double eps=1e-12;
pair<double,int> t[N];
int top;
ll sum[N];
int main(){
	int n;
	scanf("%d",&n);
	rep(i,1,n+1){
		double h;
		scanf("%lld",&sum[i]);
		h=sum[i];
		sum[i]+=sum[i-1];
		if(!top)t[++top]={h,1};
		else{
			int tot=1;
			//cout<<t[top].fi<<' '<<h<<' '<<top<<" h\n";
			while(top&&t[top].fi>=h+eps){
				tot+=t[top].se;
				h=(sum[i]-sum[i-tot])*1.0/tot;
				--top;
			}
		//	cout<<top<<"top\n";
			t[++top]={h,tot};
		}
	//	cout<<top<<"check\n";
	}
	rep(i,1,top+1){
		rep(j,0,t[i].se)printf("%.9lf\n",t[i].fi);
	}
}