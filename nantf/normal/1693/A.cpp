#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222,mod=998244353;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0;bool f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
inline int qmo(int x){return x+((x>>31)&mod);}
int n,a[maxn];
ll l[maxn],r[maxn];
void clear(){
	FOR(i,0,n+1) a[i]=l[i]=r[i]=0;
}
void solve(){
	n=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,n){
		r[i]=l[i]+a[i];
		l[i+1]=r[i];
	}
	if(l[n+1]) puts("No");
	else{
		bool flag=true;
		FOR(i,1,n) if(l[i]<0 || r[i]<0) flag=false;
		FOR(i,1,n) if(!r[i]){
			FOR(j,i+1,n) if(l[j] || r[j]) flag=false;
			break;
		}
		puts(flag?"Yes":"No");
	}
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}