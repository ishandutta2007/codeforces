#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=333333,mod=998244353;
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
inline int qmo(int x){return x+(x>>31?mod:0);}
int n;
char s[maxn];
void solve(){
	n=read();
	scanf("%s",s);
	int hhh=1;
	char wtf='\0';
	FOR(i,0,n-1) if(s[i]!='-'){
		if(wtf!='\0' && wtf!=s[i]) hhh=0;
		wtf=s[i];
	}
	int ans=0;
	FOR(i,0,n-1){
		if(s[i]=='-' || s[(i+1)%n]=='-') ans++;
		else ans+=hhh;
	}
	printf("%d\n",ans);
}
int main(){
	int T=read();
	while(T--) solve();
}