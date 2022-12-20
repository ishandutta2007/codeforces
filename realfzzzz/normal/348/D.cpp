#include<cctype>
#include<cstdio>
using namespace std;
inline int readint(){
	int x=0;
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
const int maxn=3e3+5;
int n,m;
char s[maxn][maxn];
typedef long long ll;
const ll mod=1e9+7;
ll f[maxn][maxn],g[maxn][maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	for(int i=0;i<n;i++) scanf("%s",s[i]);
	for(int i=n-1;i>=0;i--) for(int j=m-2;j>=0;j--) if(s[i][j]=='.'){
		if(i==n-1&&j==m-2) f[i][j]=1;
		if(i<n-1&&s[i+1][j]=='.') f[i][j]=(f[i][j]+f[i+1][j])%mod; 
		if(j<m-2&&s[i][j+1]=='.') f[i][j]=(f[i][j]+f[i][j+1])%mod; 
	}
	for(int i=n-2;i>=0;i--) for(int j=m-1;j>=0;j--) if(s[i][j]=='.'){
		if(i==n-2&&j==m-1) g[i][j]=1;
		if(i<n-2&&s[i+1][j]=='.') g[i][j]=(g[i][j]+g[i+1][j])%mod; 
		if(j<m-1&&s[i][j+1]=='.') g[i][j]=(g[i][j]+g[i][j+1])%mod; 
	}
	printf("%lld\n",(f[1][0]*g[0][1]%mod+mod-f[0][1]*g[1][0]%mod)%mod);
	return 0;
}