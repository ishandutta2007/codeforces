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
const int maxn=1e3+5;
int n,d[maxn],c[maxn],ord[maxn];
int main(){
#ifdef LOCAL
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++) d[i]=read();
		for(int i=1;i<=n;i++) c[i]=0;
		for(int i=1;i<=n;i++) ord[i]=i;
		sort(ord+1,ord+n+1,[](int a,int b){
			return d[a]>d[b];
		});
		for(int i=1;i<=n;i++){
			int u=ord[i];
			if(c[u]) continue;
			vector<int> vec={u};
			for(int j=0;j<d[u];j++){
				printf("? %d\n",u);
				fflush(stdout);
				int v=read();
				if(c[v]){
					for(int x:vec) c[x]=c[v];
					vec.clear();
					break;
				}
				else vec.push_back(v);
			}
			for(int x:vec) c[x]=u;
		}
		printf("! ");
		for(int i=1;i<=n;i++) printf("%d ",c[i]);
		printf("\n");
		fflush(stdout);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}