#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int cnt,ans;
ll x_0,y_0,ax,ay,bx,by,xs,ys,t,x[maxn],y[maxn];
ll dis(ll x1,ll y1,ll x2,ll y2){
	return abs(x1-x2)+abs(y1-y2);
}
int main(){
	x_0=read();y_0=read();ax=read();ay=read();bx=read();by=read();xs=read();ys=read();t=read();
	x[0]=x_0;y[0]=y_0;
	while(true){
		ll tx=x[cnt]*ax+bx,ty=y[cnt]*ay+by;
		if((tx-bx)/ax!=x[cnt] || (ty-by)/ay!=y[cnt] || tx>1e18 || ty>1e18) break;
		x[++cnt]=tx;y[cnt]=ty;
	}
	FOR(i,0,cnt) FOR(j,0,i) FOR(k,i,cnt){
		if(dis(xs,ys,x[i],y[i])+min(dis(x[i],y[i],x[j],y[j]),dis(x[i],y[i],x[k],y[k]))+dis(x[j],y[j],x[k],y[k])<=t)
			ans=max(ans,k-j+1);
	}
	FOR(i,0,cnt) FOR(j,0,i){
		if(dis(xs,ys,x[i],y[i])+dis(x[i],y[i],x[j],y[j])<=t)
			ans=max(ans,i-j+1);
	}
	FOR(i,0,cnt) FOR(j,i,cnt){
		if(dis(xs,ys,x[i],y[i])+dis(x[i],y[i],x[j],y[j])<=t)
			ans=max(ans,j-i+1);
	}
	printf("%d\n",ans);
}