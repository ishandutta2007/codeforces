#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define vi vector<int>
#define vl vector<long long>
#define ci ios::sync_with_stdio(false)
#define int long long
using namespace std;
typedef long long ll;
const int N=1e5+55;
struct he{
	int id,val;
	friend bool operator < (const he x,const he y){
		return x.val>y.val;
	}
};
struct node{
	int next,to,dis;
}a[N*2];
int head[N],cnt,qq;
void add(int e,int r,int t){
	a[++cnt].next=head[e];a[cnt].to=r;a[cnt].dis=t;head[e]=cnt;
}
int n,m,x,y,z,dis[N],pd[N];
priority_queue<he>q;
void init(){
	memset(dis,10,sizeof(dis));
	q.push((he){1,0});
	dis[1]=0;
	while(q.size()){
		he u=q.top();
		q.pop();
		if(pd[u.id])continue;
		pd[u.id]=1;
		for(int i=head[u.id];i;i=a[i].next){
			if(dis[a[i].to]>dis[u.id]+a[i].dis){
				dis[a[i].to]=dis[u.id]+a[i].dis;
				q.push((he){a[i].to,dis[a[i].to]});
			}
		}
	}
}
vi v[N];
int g[N];
void calc(){
	memset(g,10,sizeof(g));
	v[0].pb(1);g[1]=0;
	for(int i=0;i<=y;i++){
		for(int k=0;k<v[i].size();k++){
			if(g[v[i][k]]<i)continue;
			for(int j=head[v[i][k]];j;j=a[j].next){
				if(g[a[j].to]>g[v[i][k]]+dis[v[i][k]]+a[j].dis-dis[a[j].to]){
					g[a[j].to]=g[v[i][k]]+dis[v[i][k]]+a[j].dis-dis[a[j].to];
					if(g[a[j].to]<=y){
						v[g[a[j].to]].pb(a[j].to);
					}
				}
			}
		}
		vector<int>().swap(v[i]);
	}
	for(int i=1;i<=n;i++)dis[i]=min((int)1e15,g[i]+dis[i]);
}
signed main(){
	scanf("%lld%lld%lld",&n,&m,&qq);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
	}
	init();
	for(int i=1;i<=qq;i++){
		scanf("%lld",&x);
		if(x==1){
			scanf("%lld",&y);
			if(dis[y]>=1e15)puts("-1");
			else printf("%lld\n",dis[y]);
		}
		if(x==2){
			scanf("%lld",&y);
			for(int k=1;k<=y;k++){
				scanf("%lld",&z);
				a[z].dis++;
			}
			calc();
		}
	}
	init();
	return 0;
}