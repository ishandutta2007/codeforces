#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int n,m;
P<int,P<int,int>> p[305];
int it[305*305],cnt;
P<int,int> ans[305*305];
int fa[55];
int getfa(int x){
	RE (x==fa[x])?x:(fa[x]=getfa(fa[x]));
}
int merge(int x,int y){
	x=getfa(x);
	y=getfa(y);
	if(x!=y){
		fa[x]=y;
		RE 1;
	} 
	RE 0;
}
int now;
bool cmp(P<int,P<int,int> > x,P<int,P<int,int> > y){
	RE (abs(x.F-now)<abs(y.F-now));
}
void solve(int x){
	FOR(i,1,n)fa[i]=i;
	now=it[x];
	sort(p+1,p+m+1,cmp);
	FOR(i,1,m){
		if(merge(p[i].S.F,p[i].S.S)){
			if(p[i].F<=it[x]){
				ans[x].S++;
				ans[x].F-=p[i].F;
			}else{
				ans[x].S--;
				ans[x].F+=p[i].F;
			}
		}
	}
}
int get(int num){
	int pp=upb(it+1,it+cnt+1,num)-it-1;
//	cout<<it[pp]<<' '<<ans[pp].S<<' '<<ans[pp].F<<' '<<ans[pp].S*num+ans[pp].F<<'\n';
	int t=ans[pp].S*num+ans[pp].F;
	RE t;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,m){
		cin>>p[i].S.F>>p[i].S.S>>p[i].F;
	}
	FOR(i,1,m){
		FOR(j,i+1,m){
			it[++cnt]=(p[i].F+p[j].F+2)/2;
		}
		it[++cnt]=p[i].F;
	}
	it[++cnt]=0;
	sort(it+1,it+cnt+1);
//	cnt=unique(it+1,it+cnt+1)-it;
	FOR(i,1,cnt){
		solve(i);
	}
	int tp,k,a,b,c;
	cin>>tp>>k>>a>>b>>c;
	int lst=0,o=0;
	FOR(i,1,tp){
		cin>>lst;
		o^=get(lst);
	}
	FOR(i,tp+1,k){
		lst=(1ll*lst*a+b)%c;
		o^=get(lst);
	}
	cout<<o;
	RE 0;
}