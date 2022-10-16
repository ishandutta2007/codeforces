#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111111,mod=998244353,INF=1e9;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,c,a[maxn],pre[maxn];
void clear(){
	FOR(i,1,c) pre[i]=0;
}
void solve(){
	n=read();c=read();
	FOR(i,1,n) a[i]=read(),pre[a[i]]++;
	FOR(i,1,c) pre[i]+=pre[i-1];
	bool flag=true;
	FOR(i,1,c) if(pre[i]!=pre[i-1]){
		FOR(j,1,c/i){
			int l=i*j,r=min(i*(j+1)-1,c);
			if(pre[r]!=pre[l-1] && pre[j]==pre[j-1]){flag=false;break;}
		}
		if(!flag) break;
	}
	puts(flag?"Yes":"No");
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}