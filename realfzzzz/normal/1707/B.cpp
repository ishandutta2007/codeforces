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
const int maxn=1e5+5;
int n,a[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		int x=0;
		while(x<n&&!a[x+1]) x++;
		for(int i=1;i<n;i++){
			if(x<i) x=i;
			for(int j=n;j>x;j--) a[j]-=a[j-1];
			sort(a+x+1,a+n+1);
			while(x<n&&!a[x+1]) x++;
		}
		printf("%d\n",a[n]);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}