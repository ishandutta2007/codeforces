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
const int maxn=5e5+5;
int n;
char s[maxn];
const int f[]={0,0,1,1,2,0,3,1,1,0,3,3,2,2,4,0,5,2,2,3,3,0,1,1,3,0,2,1,1,0,4,5,2,7,4,0,1,1,2,0,3,1,1,0,3,3,2,2,4,4,5,5,2,3,3,0,1,1,3,0,2,1,1,0,4,5,3,7,4,8,1,1,2,0,3,1,1,0,3,3,2,2,4,4,5,5,9};
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		scanf("%s",s+1);
		int cnt=0;
		for(int i=1;i<=n;i++) cnt+=s[i]=='R'?1:-1;
		if(cnt){
			printf(cnt>0?"Alice\n":"Bob\n");
			continue;
		}
		int sum=0,l=0;
		for(int i=1;i<=n;i++) if(i==n||s[i]==s[i+1]){
			if(i-l<=52) sum^=f[i-l];
			else sum^=f[(i-l-53)%34+53];
			l=i;
		}
		printf(sum?"Alice\n":"Bob\n");
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}