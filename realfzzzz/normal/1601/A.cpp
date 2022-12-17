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
const int maxn=2e5+5;
int n,a[maxn],cnt[30];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<30;i++) for(int j=1;j<=n;j++) if(a[j]>>i&1) cnt[i]++;
		for(int i=1;i<=n;i++){
			bool flag=1;
			for(int j=0;j<30;j++) flag&=cnt[j]%i==0;
			if(flag) printf("%d ",i);
		}
		printf("\n");
	}
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}