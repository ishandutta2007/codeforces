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
int n,a[maxn],b[maxn],c[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=n;i++) b[i]=read();
		vector<pair<int,int>> a2,b2={{0,0}};
		for(int l=1;l<=n;){
			int r=l;
			while(r<n&&a[r]==a[r+1]) r++;
			a2.push_back({a[l],r-l+1});
			l=r+1;
		}
		for(int l=1;l<=n;){
			int r=l;
			while(r<n&&b[r]==b[r+1]) r++;
			b2.push_back({b[l],r-l+1});
			l=r+1;
		}
		for(int i=1;i<=n;i++) c[i]=0;
		bool flag=1;
		while(a2.size()){
			auto x=a2.back(),y=b2.back();
			if(x.first==y.first){
				c[x.first]-=x.second-y.second;
				if(c[x.first]<0){
					flag=0;
					break;
				}
				a2.pop_back();
				b2.pop_back();
			}
			else{
				c[x.first]-=x.second;
				if(c[x.first]<0){
					flag=0;
					break;
				}
				a2.pop_back();
			}
		}
		printf(flag?"YES\n":"NO\n");
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}