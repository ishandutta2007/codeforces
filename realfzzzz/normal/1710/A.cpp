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
const int maxk=1e5+5;
int n,m,k,a[maxk];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		m=read();
		k=read();
		for(int i=1;i<=k;i++) a[i]=read();
		sort(a+1,a+k+1,greater<int>());
		bool flag=0;
		int s=0;
		for(int i=1;i<=k&&a[i]>=n*2;i++){
			s+=a[i]/n;
			flag|=i*2<=m&&s>=m;
		}
		s=0;
		for(int i=1;i<=k&&a[i]>=m*2;i++){
			s+=a[i]/m;
			flag|=i*2<=n&&s>=n;
		}
		printf(flag?"Yes\n":"No\n");
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}