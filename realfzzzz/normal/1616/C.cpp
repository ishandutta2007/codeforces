#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=70+5;
int n,a[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		int ans=n-1;
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++){
			int cnt=0;
			for(int k=1;k<=n;k++) cnt+=(a[j]-a[i])*(k-i)%(j-i)!=0||a[i]+(a[j]-a[i])*(k-i)/(j-i)!=a[k];
			ans=min(ans,cnt);
		}
		printf("%d\n",ans);
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}