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
int n,tp[3],al;
char s[3][maxn],ans[maxn];
void solve(){
	n=read();
	FOR(i,0,2){
		scanf("%s",s[i]+1);
		int c=0;
		FOR(j,1,2*n) if(s[i][j]=='1') c++; 
		tp[i]=c>=n;
	}
	FOR(i,0,2) FOR(j,i+1,2) if(tp[i]==tp[j]){
		int t=tp[i],x=1,y=1;
		al=0;
		while(x<=2*n || y<=2*n){
			while(x<=2*n && s[i][x]!=t+'0') ans[++al]=s[i][x++];
			while(y<=2*n && s[j][y]!=t+'0') ans[++al]=s[j][y++];
			if(x>2*n && y>2*n) break;
			ans[++al]=t+'0';
			x++;y++;
		}
		FOR(k,1,al) putchar(ans[k]);
		puts("");
		return;
	}
}
int main(){
	int T=read();
	while(T--) solve();
}