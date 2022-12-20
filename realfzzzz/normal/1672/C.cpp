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
int n,a[maxn],s[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<n;i++) s[i]=s[i-1]+(a[i]==a[i+1]);
		int ans=0;
		for(int i=n-1;i>0;i--) if(s[i]>s[i-1]){
			if(!s[i-1]) break;
			else{
				ans++;
				s[i-2]=i>=3?s[i-3]:0;
				s[i-1]=s[i-2]+1;
			}
		}
		printf("%d\n",ans);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}