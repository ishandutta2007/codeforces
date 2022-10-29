#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2e3+9;
struct node{
	int u,v;
	ll d;
}e[N*N];
bool cmp(node a,node b){
	return a.d<b.d;
}
int fa[N],k[N],cnt,cnt1,cnt2,ans[N],x[N],y[N],c;
pii ans2[N];
void add(int u,int v,ll d){
	e[cnt++]=(node){u,v,d};
}
ll get(int i,int j){
	return 1ll*(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])); 
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
} 
int main()
{
	int n;
	scanf("%d",&n);
	rep(i,1,n+1)scanf("%d%d",&x[i],&y[i]);
	rep(i,1,n+1)scanf("%d",&c),add(n+1,i,c);
	rep(i,1,n+1)scanf("%d",&k[i]);
	rep(i,1,n+1){
		rep(j,i+1,n+1){
			add(i,j,get(i,j));
		}
	}
	sort(e,e+cnt,cmp);
	rep(i,1,n+1)fa[i]=i;
	ll cost=0;
	rep(i,0,cnt){
		int u=e[i].u,v=e[i].v;
		if(find(u)!=find(v)){
			fa[find(u)]=find(v);
			cost+=e[i].d;
			if(u==n+1){
				ans[cnt1++]=v;
			}
			else{
				ans2[cnt2++]={u,v};
			}
		}
	}
	printf("%lld\n%d\n",cost,cnt1);
	rep(i,0,cnt1)printf("%d ",ans[i]);
	printf("\n");
	printf("%d\n",cnt2);
	rep(i,0,cnt2)printf("%d %d\n",ans2[i].fi,ans2[i].se);
}