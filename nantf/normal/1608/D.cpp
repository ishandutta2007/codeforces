#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111111,mod=998244353;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,c[3][3],a,b,cc;
char s[10];
bool flag,f1=true,f2=true;
inline int id(char c){
	return c=='B'?0:c=='W'?1:2;
}
int main(){
	n=read();
	FOR(i,1,n){
		scanf("%s",s);
		if(s[0]=='?'){
			if(s[1]=='?') a+=2,b++,cc++;
			if(s[1]=='B') f1=false,a++;
			if(s[1]=='W') f2=false,a++,b++;
		}
		else if(s[0]=='B'){
			f2=false;
			if(s[1]=='?') a++;
			if(s[1]=='B') f1=false,b--,flag=true;
			if(s[1]=='W') f2=false;
		}
		else{
			f1=false;
			if(s[1]=='?') a++,b++;
			if(s[1]=='B') f1=false;
			if(s[1]=='W') f2=false,b++,flag=true;
		}
	}
	if(b<0 || b>a) puts("0");
	else{
		int ans=1;
		FOR(i,1,b) ans=1ll*ans*i%mod;
		ans=qpow(ans,mod-2);
		FOR(i,a-b+1,a) ans=1ll*ans*i%mod;
		if(!flag){
			ans=(ans-qpow(2,cc)+mod)%mod;
			if(f1) ans=(ans+1)%mod;
			if(f2) ans=(ans+1)%mod;
		}
		printf("%d\n",ans);
	}
}