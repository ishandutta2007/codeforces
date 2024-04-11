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
const int maxn=1e6+5;
int n,a[maxn];
bool vis[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=n;i++){
			int u=i;
			vector<int> s;
			while(!vis[u]){
				vis[u]=1;
				s.push_back(u);
				u-=a[u];
			}
			vector<int> ans={u};
			while(s.back()!=u){
				ans.push_back(s.back());
				s.pop_back();
			}
			printf("%d\n",(int)ans.size());
			for(int i:ans) printf("%d ",i);
			printf("\n");
			break;
		}
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}