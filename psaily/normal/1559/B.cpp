#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define inf 0x3f3f3f3f

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<long long,int> pli;
typedef double db;
// head

const int N=1e5+5;
int n,a[N];
char str[N];
int f[N][2],g[N][2];

int getc(char c) {
	if (c=='R') return 1;
	if (c=='B') return 0;
	else return 2;
}

void dfs(int m,int c) {
	if (m!=1) dfs(m-1,g[m][c]);
	printf("%c",c==1?'R':'B');
}

int main() {
	int T;
	cin>>T;
	while (T--) {
		scanf("%d%s",&n,str+1);
		rep(i,0,n+1) f[i][0]=f[i][1]=inf;
		rep(i,1,n+1) a[i]=getc(str[i]);
		
		if (a[1]==2) f[1][1]=f[1][0]=0;
		else f[1][a[1]]=0;
		
		rep(i,2,n+1) {
			// debug(a[i]);
			if (a[i]==0) {
				if (f[i-1][1]<=f[i-1][0]+1) f[i][0]=f[i-1][1],g[i][0]=1;
				else f[i][0]=f[i-1][0]+1,g[i][0]=0;
			}else if (a[i]==1) {
				if (f[i-1][1]+1<=f[i-1][0]) f[i][1]=f[i-1][1]+1,g[i][1]=1;
				else f[i][1]=f[i-1][0],g[i][1]=0;
			}else {// a[i]==2
				if (f[i-1][1]<=f[i-1][0]+1) f[i][0]=f[i-1][1],g[i][0]=1;
				else f[i][0]=f[i-1][0]+1,g[i][0]=0;
				if (f[i-1][1]+1<=f[i-1][0]) f[i][1]=f[i-1][1]+1,g[i][1]=1;
				else f[i][1]=f[i-1][0],g[i][1]=0;
			}
			// bug(i),bug(f[i][0]),debug(f[i][1]);
			// bug(i),bug(g[i][0]),debug(g[i][1]);
		}
		
		if (f[n][0]<f[n][1]) dfs(n,0);
		else dfs(n,1);
		puts("");
	}
	return 0;	
}