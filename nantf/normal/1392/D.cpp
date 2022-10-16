#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=200020,mod=998244353;
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
inline int qmo(int x){return x+(x>>31)*mod;}
int n,hhh[maxn];
char s[maxn];
void solve(){
	n=read();
	scanf("%s",s+1);
	int at=0;
	FOR(i,1,n) if(i==1 && s[1]!=s[n] || i!=1 && s[i]!=s[i-1]) at=i;
	if(!at) printf("%d\n",(n+2)/3);
	else{
		FOR(i,at,n) hhh[i-at+1]=s[i]=='L'?1:2;
		FOR(i,1,at-1) hhh[n-at+1+i]=s[i]=='L'?1:2;
		int cur=0,ans=0;
		FOR(i,1,n){
			if(hhh[i]==hhh[i-1]) cur++;
			else ans+=cur/3,cur=1;
		}
		ans+=cur/3;
		printf("%d\n",ans);
	} 
}
int main(){
	int T=read();
	while(T--) solve();
}