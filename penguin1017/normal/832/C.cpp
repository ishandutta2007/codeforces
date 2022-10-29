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
#define all(x) x.begin(),x.end()
using namespace std;
const int N=1e5+9;
const double eps=1e-6;
const ll mod=998244353;
pii L[N],R[N];
int lcnt,rcnt;
int dis=1e6,n,s;
double lt=1e6,rt=1e6,lmin=1e6,rmin=1e6;
int findl(int x){
	int l=0,r=lcnt;
	while(l<r){
		int m=l+r>>1;
		if(L[m].fi<=x)l=m+1;
		else r=m;
	}
	return l-1;
}
int findr(int x){
	int l=0,r=rcnt;
	while(l<r){
		int m=l+r>>1;
		if(R[m].fi>x)r=m;
		else l=m+1;
	}
	if(!l)return l;
	if(R[l-1].fi>=x)return l-1;
	return l;
}
void solve(){
	double ans=min(max(lt,rmin),max(rt,lmin));int l=L[0].fi,r=R[rcnt-1].fi+1;
//	cout<<l<<" "<<r<<' '<<ans<<"??\n";
	while(l<r){
		int m=(l+r)/2;
		int posl=findl(m),posr=findr(m);
		double t1=1.0*(m-L[posl].fi)/(s-L[posl].se),t2=1.0*(R[posr].fi-m)/(s-R[posr].se);
	//	cout<<m<<' '<<t1<<' '<<t2<<"???\n";
		if(t1+eps>lt)t1=lt;
		else{
			double last=L[posl].fi-t1*L[posl].se;
		//	de(last);
			t1=min(t1+last/(s+L[posl].se),lt);
		}
		if(t2+eps>rt)t2=rt;
		else{
			double last=dis-R[posr].fi-t2*R[posr].se;
			t2=min(t2+last/(s+R[posr].se),rt);
		}
		if(t1<t2)l=m+1;
		else r=m;
		ans=min(ans,max(t1,t2));
	//	cout<<t1<<' '<<t2<<' '<<lt<<' '<<rt<<' '<<m<<' '<<posl<<posr<<"check\n";
	//	system("pause");
	}
//	cout<<l<<"check\n";
	printf("%.6lf",ans);
	
}
int main(){
	scanf("%d%d",&n,&s);
	while(n--){
		int x,v,t;
		scanf("%d%d%d",&x,&v,&t);
		if(t==1)L[lcnt++]={x,v},lt=min(lt,1.0*x/v),lmin=min(lmin,1.0*x/(v+s));
		else R[rcnt++]={x,v},rt=min(rt,1.0*(dis-x)/v),rmin=min(rmin,1.0*(dis-x)/(v+s));
	}
	sort(L,L+lcnt);
	sort(R,R+rcnt);
	solve();
}
/*
4 1000000
500000 500000 1
500000 500000 1
500000 500000 2
500000 500000 2
*/