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
int read(){
	char c=getchar();
	int x=1,s=0;
	while(c<'0'||c>'9'){
	   if(c=='-')x=-1;c=getchar();
	}
	while(c>='0'&&c<='9'){
	   s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
const int N=2e5+5e4+55;
vector<pii>v[N];
void add(int e,int r,int t){
	v[e].pb(mp(r,t));
}
int n,x,y,z,in[N],id[N],topp,head=1,bj[N],ne,f[N][2],st[N],top,dl[N],tou;
struct node{
	int a,b;
}stt[N];
int cmpp(node x,node y){
	return in[x.a]>in[y.a];
}
int cmp(int x,int y){
	return in[x]<in[y];
}
struct Heap{
	priority_queue<int>q,p;
	int summ;
	void clear(){summ=0;}
	void ql(){while(q.size() and p.size() and q.top()==p.top())q.pop(),p.pop();}
	int top(){ql();return q.top();}
	int size(){return q.size()-p.size();}
	int insert(int x){q.push(x);summ+=x;}
	int clear(int x){p.push(x);summ-=x;}
	int pop(){ql();summ-=q.top();q.pop();}
}q[N];
void jia(int u){
	for(int i=0;i<v[u].size();i++){
		if(in[v[u][i].fi]<=ne)break;
		q[v[u][i].fi].insert(v[u][i].se);
	}
}
void dfs(int u,int fa){
	
	bj[u]=ne;
	for(int i=0;i<v[u].size();i++){
		if(in[v[u][i].fi]<=ne)break;
		if(bj[v[u][i].fi]==ne)continue;
		dfs(v[u][i].fi,u);
	}
	while(q[u].size()>in[u]-ne)q[u].pop();
	int yy=in[u]-ne,xx=0;top=tou=0;
	if(u==1){
		new char;
	}
	for(int i=0;i<v[u].size();i++){
		if(in[v[u][i].fi]<=ne)break;
		if(v[u][i].fi==fa)continue;
		if(f[v[u][i].fi][1]+v[u][i].se<=f[v[u][i].fi][0]){
			yy--;
			xx+=f[v[u][i].fi][1]+v[u][i].se;
		}
		else{
			xx+=f[v[u][i].fi][0];
			q[u].insert(f[v[u][i].fi][1]+v[u][i].se-f[v[u][i].fi][0]);
			dl[++tou]=f[v[u][i].fi][1]+v[u][i].se-f[v[u][i].fi][0];
		}
	}
	while(q[u].size() and q[u].size()>yy){
		st[++top]=q[u].top();
		q[u].pop();
	}
	f[u][0]=q[u].summ+xx;
	if(q[u].size() and q[u].size()==yy){
		st[++top]=q[u].top();
		q[u].pop();
	}
	f[u][1]=q[u].summ+xx;
	for(int i=1;i<=tou;i++)q[u].clear(dl[i]);
	for(int i=1;i<=top;i++)q[u].insert(st[i]);
}
signed main(){
//	freopen("data.in","r",stdin);
	n=read();
	int sum1=0;
	for(int i=1;i<n;i++){
		x=read();y=read();z=read();
		in[x]++;in[y]++;
		add(x,y,z);
		add(y,x,z);
		sum1+=z;
	}
	for(int i=1;i<=n;i++){q[i].clear();id[i]=i;topp=v[i].size();for(int k=1;k<=topp;k++)stt[k]={v[i][k-1].fi,v[i][k-1].se};sort(stt+1,stt+topp+1,cmpp);for(int k=1;k<=topp;k++)v[i][k-1].fi=stt[k].a,v[i][k-1].se=stt[k].b;}
	sort(id+1,id+n+1,cmp);
	for(int i=0;i<n;i++){
		if(i==0){
			cout<<sum1<<" ";
			continue;
		}
		while(head<=n and in[id[head]]<=i)jia(id[head]),head++;
		int ans=0;
		ne=i;
		for(int k=head;k<=n;k++){
			f[id[k]][0]=f[id[k]][1]=0;
			if(bj[id[k]]==ne)continue;
			dfs(id[k],0);
			ans+=f[id[k]][0];
		}
		printf("%lld ",ans);
	}
	return 0;
}