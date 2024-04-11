#include<algorithm>
#include<cctype>
#include<cstdio>
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
const int maxn=500+5;
int n;
ll a[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=0;i<n;i++) a[i]=readint();
	ll ans=0;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) for(int k=0;k<n;k++)
		ans=max(ans,a[i]|a[j]|a[k]);
	printf("%lld\n",ans);
	return 0;
}