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
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		int n,m;
		n=read();
		m=read();
		int mx=0;
		ll mnv=0,mxv=0;
		for(int i=1;i<=n;i++){
			ll s=0;
			for(int j=1;j<=m;j++) s+=read()*j;
			if(i==1||s<mnv) mnv=s;
			if(i==1||s>mxv){
				mx=i;
				mxv=s;
			}
		}
		printf("%d %lld\n",mx,mxv-mnv);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}