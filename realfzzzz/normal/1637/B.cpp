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
const int maxn=100+5;
int n,a[maxn],f[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		int ans=0;
		for(int i=1;i<=n;i++){
			f[i-1]=0;
			for(int j=i;j<=n;j++){
				f[j]=0;
				set<int> s;
				for(int k=0;k<=n;k++) s.insert(k);
				for(int k=j;k>=i;k--){
					if(a[k]<=n) s.erase(a[k]);
					f[j]=max(f[j],f[k-1]+*s.begin()+1);
				}
				ans+=f[j];
			}
		}
		printf("%d\n",ans);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}