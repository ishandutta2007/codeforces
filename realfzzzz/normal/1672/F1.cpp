#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e5+5;
int n,a[maxn],b[maxn],ord[maxn];
vector<int> q[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++) vector<int>().swap(q[i]);
		for(int i=1;i<=n;i++) q[a[i]=read()].push_back(i);
		for(int i=1;i<=n;i++) ord[i]=i;
		sort(ord+1,ord+n+1,[](int a,int b){
			return q[a].size()>q[b].size();
		});
		for(int i=1;i<=n;i++){
			int u=ord[i],v=ord[i+1];
			for(int j=0;j<(int)q[v].size();j++) b[q[u][j]]=v;
			for(int j=q[v].size();j<(int)q[u].size();j++) b[q[u][j]]=ord[1];
		}
		for(int i=1;i<=n;i++) printf("%d ",b[i]);
		printf("\n");
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}