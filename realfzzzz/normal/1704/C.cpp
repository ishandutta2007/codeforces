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
const int maxm=2e5+5;
int n,m,a[maxm];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		m=read();
		for(int i=1;i<=m;i++) a[i]=read();
		sort(a+1,a+m+1);
		int a1=a[1];
		for(int i=1;i<m;i++) a[i]=a[i+1]-a[i]-1;
		a[m]=a1-a[m]+n-1;
		sort(a+1,a+m+1,greater<int>());
		int ans=m;
		for(int i=1;i<=m;i++)
			if(a[i]>i*4-3) ans+=i*4-3;
			else if(a[i]==i*4-3) ans+=i*4-4;
			else ans+=a[i];
		printf("%d\n",ans);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}