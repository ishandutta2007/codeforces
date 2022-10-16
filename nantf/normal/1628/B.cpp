#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111111,mod=998244353;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
#define YES return puts("YES"),clear()
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
int n,in1[26],f2[26][26],l2[26][26],f3[26][26][26],l3[26][26][26];
char s[maxn];
void clear(){
	FOR(i,0,25) in1[i]=false;
	FOR(i,0,25) FOR(j,0,25) f2[i][j]=l2[i][j]=0;
	FOR(i,0,25) FOR(j,0,25) FOR(k,0,25) f3[i][j][k]=l3[i][j][k]=0;
}
void solve(){
	n=read();
	FOR(i,1,n){
		scanf("%s",s+1);
		int l=strlen(s+1);
		if(l==1) in1[s[1]-'a']=true;
		if(l==2){
			int a=s[1]-'a',b=s[2]-'a';
			if(!f2[a][b]) f2[a][b]=i;
			l2[a][b]=i;
		}
		if(l==3){
			int a=s[1]-'a',b=s[2]-'a',c=s[3]-'a';
			if(!f3[a][b][c]) f3[a][b][c]=i;
			l3[a][b][c]=i;
		}
	}
	FOR(i,0,25) if(in1[i] || f2[i][i]) YES;
	FOR(i,0,25) FOR(j,0,25) if(f2[i][j] && f2[j][i] || f3[i][j][i]) YES;
	FOR(i,0,25) FOR(j,0,25) FOR(k,0,25) if(f3[i][j][k] && f3[k][j][i]) YES;
	FOR(i,0,25) FOR(j,0,25) FOR(k,0,25) if(f2[i][j] && l3[k][j][i] && f2[i][j]<=l3[k][j][i]) YES;
	FOR(i,0,25) FOR(j,0,25) FOR(k,0,25) if(f3[i][j][k] && l2[j][i] && f3[i][j][k]<=l2[j][i]) YES;
	puts("NO");
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}