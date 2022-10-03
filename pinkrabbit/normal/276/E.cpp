#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,q,cnt;
int dep[MN],col[MN];
vector<int>G[MN],li[MN],bit[MN];
void DFS(int u,int fz,int c){
	dep[u]=dep[fz]+1;
	col[u]=c;
	li[c].pb(u);
	for(auto v:G[u])if(v!=fz)DFS(v,u,c);
}
void Add(int id,int i,int val){
//	printf("Add(%d,%d,%d)\n",id,i,val);
	if(id==0)++i;
	if(i==0)return;
	for(;i<=(int)(li[id].size()-1);i+=i&-i)bit[id][i]+=val;
}
int Qur(int id,int i){
//	printf("Qur(%d,%d)\n",id,i);
	if(id==0)++i;
//	F(i,1,(int)(li[id].size()-1))printf("bit[%d][%d]=%d\n",id,i,bit[id][i]);
	int a=0;
	for(;i;i-=i&-i)a+=bit[id][i];
//	printf("a=%d\n",a);
	return a;
}
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&q);
	F(i,2,n){
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].pb(y),G[y].pb(x);
	}
	dep[1]=0;
	for(auto u:G[1])li[++cnt].pb(0),DFS(u,1,cnt),bit[cnt].resize(li[cnt].size());
	li[0].resize(n+1);
	bit[0].resize(n+1);
	while(q--){
		int op;
		scanf("%d",&op);
		if(!op){
			int id,val,dis;
			scanf("%d%d%d",&id,&val,&dis);
			if(id==1){
				Add(0,min(n,dis),val);
			}else if(dis<dep[id]){
				Add(col[id],min((int)(li[col[id]].size()-1),dep[id]+dis),val);
				Add(col[id],dep[id]-dis-1,-val);
			}else{
				int d2=dis-dep[id];
				d2=min(d2,n);
				Add(0,d2,val);
				Add(col[id],min((int)(li[col[id]].size()-1),dep[id]+dis),val);
				Add(col[id],min((int)(li[col[id]].size()-1),d2),-val);
			}
		}else{
			int id;
			scanf("%d",&id);
			if(id==1)printf("%d\n",Qur(0,n-1));
			else printf("%d\n",Qur(0,n-1)-Qur(0,dep[id]-1)+Qur(col[id],(int)(li[col[id]].size()-1))-Qur(col[id],dep[id]-1));
		}
	}
}	return 0;
}