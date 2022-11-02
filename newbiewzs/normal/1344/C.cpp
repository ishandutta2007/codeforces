#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
//#define int long long
using namespace std;
typedef long long ll;
int read(){
	char c=getchar();int s=0;int x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
const int N=2e5+55;
int n,m,a[N],b[N];
struct node{
	vi v[N];
	void add(int x,int y){
		v[x].pb(y);
	}
	int low[N],dfn[N],tot,st[N],top,pd[N],flag,dx;
	void tarjan(int u){
		st[++top]=u;dfn[u]=low[u]=++tot;
		for(int i=0;i<v[u].size();i++){
			if(!dfn[v[u][i]]){
				tarjan(v[u][i]);
				low[u]=min(low[u],low[v[u][i]]);
			}
			else if(!pd[v[u][i]]){
				low[u]=min(low[u],dfn[v[u][i]]);
			}
		}
		if(dfn[u]==low[u]){
			if(st[top]!=u)flag=1;
			while(st[top]!=u)top--;
			top--;
		}
	}
	int f[N],in[N];
	void solve(){
		int tot=0;
		queue<int>q;
		for(int i=1;i<=n;i++)if(!in[i])q.push(i);
		for(int i=1;i<=n;i++)f[i]=i;
		while(q.size()){
			int u=q.front();tot++;
			q.pop();
			for(int i=0;i<v[u].size();i++){
				f[v[u][i]]=min(f[v[u][i]],f[u]);
				in[v[u][i]]--;
				if(!in[v[u][i]])q.push(v[u][i]);
			}
		}
		if(tot!=n){
			cout<<"-1";
			exit(0);
		}
	}
}t1,t2;
int main(){
	n=read();m=read();
	for(int i=1;i<=m;i++){
		a[i]=read();b[i]=read();
		t1.add(a[i],b[i]);
		t1.in[b[i]]++;
		t2.add(b[i],a[i]);
		t2.in[a[i]]++;
	}
	t1.solve();
	t2.solve();
	int ans=0;
	for(int i=1;i<=n;i++){
		if(t1.f[i]==t2.f[i] and t1.f[i]==i)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		if(t1.f[i]==t2.f[i] and t1.f[i]==i)cout<<"A";
		else cout<<"E";
	}
	return 0;
}