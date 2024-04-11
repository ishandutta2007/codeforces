#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}
const int N=205;
const int M=1e5+5;
const int inf=1e9+7;
int n,v[N],st[M],dis[N],top,s,t,js1,js2,f[N],cur[N];
struct node{
	int next,to,dis;
}a[M];
int head[N],cnt=1;
void add(int e,int r,int t){
	a[++cnt].next=head[e];a[cnt].to=r;a[cnt].dis=t;head[e]=cnt;
	a[++cnt].next=head[r];a[cnt].to=e;a[cnt].dis=0;head[r]=cnt;
}
bool pd[M+5];
void init(){
	for(int i=2;i<=M;i++){
		if(!pd[i])st[++top]=i;
		for(int k=1;st[k]*i<=M and k<=top;k++){
			pd[st[k]*i]=1;
		}
	}
}
bool bfs(){
	queue<int>q;
	for(int i=s;i<=t;i++)dis[i]=0;
	dis[s]=1;q.push(s);
	while(q.size()){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=a[i].next){
			if(!dis[a[i].to] and a[i].dis){
				dis[a[i].to]=dis[u]+1;
				q.push(a[i].to);
			}
		}
	}
	return (dis[t]>=1);
}
int dfs(int u,int cos){
	if(u==t)return cos;
	int zs=0;
	for(int i=cur[u];i;i=a[i].next){
		cur[u]=i;
		if(dis[a[i].to]==dis[u]+1 and a[i].dis>0 and cos>0){
			int gg=dfs(a[i].to,min(cos,a[i].dis));
			a[i].dis-=gg;
			a[i^1].dis+=gg;
			zs+=gg;cos-=gg;
		}
	}
	if(!zs)dis[u]=0;
	return zs;
}
bool dinic(){
	int ll=0;
	while(bfs()){
		for(int i=s;i<=t;i++)cur[i]=head[i];
		ll+=dfs(s,inf);
	}
	return (ll==2*js1);
}
vector<int>g[N];
int main(){
	init();
	n=read();
	for(int i=1;i<=n;i++)v[i]=read();
	s=0;t=n+1;
	for(int i=1;i<=n;i++){
		if(v[i]%2==0){
			add(s,i,2);js1++;
		}
		else{
			add(i,t,2);js2++;
		}
	}
	if(js1!=js2){
		puts("Impossible");return 0;
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
			if(i==k)continue;
			if(v[i]%2==1 or v[k]%2==0)continue;
			if(!pd[v[i]+v[k]])add(i,k,1);
		}
	}
	if(!dinic()){
		puts("Impossible");return 0;
	}
	int zs=0;
	for(int i=1;i<=n;i++){
		if(!f[i]){
			zs++;
			g[zs].push_back(i);f[i]=1;
			int s=i;
			while(1){
				bool flag=0;
				if(v[s]%2==0){
					for(int k=head[s];k;k=a[k].next){
						if(v[a[k].to]%2==1 and a[k].dis==0 and !f[a[k].to]){
							s=a[k].to;g[zs].push_back(a[k].to);f[a[k].to]=1;flag=1;
							break;
						}
					}
				}
				else{
					for(int k=head[s];k;k=a[k].next){
						if(v[a[k].to]%2==0 and a[k].dis==1 and !f[a[k].to]){
							s=a[k].to;g[zs].push_back(a[k].to);f[a[k].to]=1;flag=1;
							break;
						}
					}
				}
				if(flag==0)break;
			}
		}
	}
	cout<<zs<<endl;
	for(int i=1;i<=zs;i++){
		cout<<g[i].size()<<" ";
		for(int k=0;k<g[i].size();k++){
			cout<<g[i][k]<<" ";
		}
		cout<<endl;
	}
	return 0;
}