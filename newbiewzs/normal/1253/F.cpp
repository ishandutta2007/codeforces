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
#include<math.h>
//#include<unordered_map>
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
#define da(x) cout<<"sese:"<<x<<endl;
#define db(x,y) cout<<"???"<<x<<" "<<y<<endl;
#define dc(x,y,z) cout<<"!!!!:"<<x<<" "<<y<<" "<<z<<endl;
#define dd(x,y,z,w) cout<<"yiw:"<<x<<" "<<y<<" "<<z<<" "<<w<<endl;
#define int long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int read(){
	char c=getchar();
	ll x=1,s=0;
	while(c<'0'||c>'9'){
	   if(c=='-')x=-1;c=getchar();
	}
	while(c>='0'&&c<='9'){
	   s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
const int N=3e5+55;
struct node{
	int x,y;
}q[N];
struct tmp{
	int x,y,z;
}a[N];
int cmp(tmp x,tmp y){
	return x.z<y.z;
}
vi cd[N];
vector<pii>v[N];
int n,m,s,x[N],y[N],z[N],ans[N];
void add(int e,int r,int t){
	v[e].pb(mp(r,t));
}
priority_queue<pii>qq;
int dis[N],pd[N],pre[N],f[N];
void dijk(){
	memset(dis,10,sizeof(dis));
	for(int i=1;i<=s;i++){
		dis[i]=0;pre[i]=i;
		qq.push(mp(0,i));
	}
	while(!qq.empty()){
		pii u=qq.top();
		qq.pop();
		if(pd[u.se])continue;
		pd[u.se]=1;
		for(unsigned int i=0;i<v[u.se].size();i++){
			if(dis[v[u.se][i].fi]>dis[u.se]+v[u.se][i].se){
				dis[v[u.se][i].fi]=dis[u.se]+v[u.se][i].se;
				pre[v[u.se][i].fi]=pre[u.se];
				qq.push(mp(-dis[v[u.se][i].fi],v[u.se][i].fi));
			}
		}
	}
}
int find(int x){
	if(f[x]!=x)return f[x]=find(f[x]);
	else return x;
}
int st[N],top;
int tpp=0;
signed main(){
	n=read();m=read();s=read();tpp=read();
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		x[i]=read();y[i]=read();z[i]=read();
		add(x[i],y[i],z[i]);add(y[i],x[i],z[i]);
	}
	for(int i=1;i<=tpp;i++){
		q[i].x=read();q[i].y=read();
		cd[q[i].x].pb(i);cd[q[i].y].pb(i);
	}
	dijk();
	for(int i=1;i<=m;i++){
		a[i].x=pre[x[i]];
		a[i].y=pre[y[i]];
		a[i].z=z[i]+dis[x[i]]+dis[y[i]];
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(cd[find(a[i].x)].size()<cd[find(a[i].y)].size())swap(a[i].x,a[i].y);
		
		if(find(a[i].x)!=find(a[i].y)){
			top=0;
			for(unsigned int k=0;k<cd[find(a[i].y)].size();k++)st[++top]=cd[find(a[i].y)][k];
			f[find(a[i].y)]=find(a[i].x);
			for(int k=1;k<=top;k++){
				int u=st[k];
				int xx=q[u].x;int yy=q[u].y;
				if(find(xx)==find(yy)){
					if(!ans[u])ans[u]=a[i].z;
				}
				else{
					cd[find(a[i].x)].pb(u);
				}
			}
		}
		
	}
	for(int i=1;i<=tpp;i++){
		printf("%lld\n",ans[i]);
	}
	return 0;
}