#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define SZ(x) ((int)(x).size())
#define prts(x) return puts(x),0
#define pirtf(x) return printf("%d\n",x),0
#define re return
typedef long long LL;
typedef double ld;
typedef pair<int,int> pii;
inline LL Pow(LL B,LL E,LL M){LL A=1;for(;E;E>>=1,B=B*B%M)E&1?A=A*B%M:0;return A;}
#define INF 0x3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f

map<int,int> mp;
set<int> st;

int n,q,m,k,ans;
int a[300005],b[300005];
char tstr[200015], *str[100005];
int v[100005][26];
char f[100005],g[100005];

int Solve(int n, char ch) {
	if (!v[n][ch - 'a']) return 0;
	char *s = str[n];
	int len = strlen(s + 1), ans = 1;
	int cnt = 0;
	F(i,1,len) {
		if(s[i] == ch) {
			++cnt;
			ans=max(ans,cnt);
		}
		else cnt=0;
	}
	if(s[1] != ch && s[len] != ch) return ans;
	int ok = 1;
	F(i,1,len) if (s[i] != ch) ok = 0;
	if(ok) return ans = max(ans, (Solve(n - 1, ch) + 1) * (len + 1) - 1);
	int L=1;
	F(i,1,len) if(s[i] == ch) ++L; else break;
	dF(i,len,1) if(s[i] == ch) ++L; else break;
	if(v[n-1][ch-'a']) ans=max(ans,L);
	return ans;
}

int main(){
	scanf("%d",&n);
	str[0]=tstr;
	F(i,1,n) {
		str[i] = str[i-1] + strlen(str[i-1] + 1) + 1, scanf("%s",str[i] + 1);
		F(j,0,25) v[i][j] = v[i-1][j];
		int len=strlen(str[i]+1);
		F(j,1,len) v[i][str[i][j]-'a']=1;
	}
//	F(i,1,n) printf("%s\n", str[i] + 1);
	F(i,'a','z') ans=max(ans,Solve(n, i));
	printf("%d\n", ans);
	return 0;
}