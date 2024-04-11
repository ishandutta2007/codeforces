#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
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
 
typedef unsigned long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<long long,int> pli;
typedef double db;
// head
 
const int mod=998244353;
const int N=505;

int n,m;
char str[N][N];
int a[N][N];

int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) scanf("%s",str[i]+1);
	
	rep(i,1,n+1) {
		int cur=0,pos=1;
		
		while (pos<=m) {
			if (str[i][pos]=='.') {
				if (cur) {
					if (pos&1) a[i][pos]=1;
					else a[i][pos]=4;
				}else {
					if (pos&1) a[i][pos]=4;
					else a[i][pos]=1;
				}
			}else {
				if (str[i-1][pos]=='X') cur=1-cur;
			}	
			pos++;
		}	
	}
	rep(i,1,n+1) rep(j,1,m+1) if (str[i][j]=='X') {
		int cnt=0;
		if (str[i][j+1]=='.') a[i][j]+=a[i][j+1],cnt++;
		if (str[i][j-1]=='.') a[i][j]+=a[i][j-1],cnt++;
		if (str[i+1][j]=='.') a[i][j]+=a[i+1][j],cnt++;
		if (str[i-1][j]=='.') a[i][j]+=a[i-1][j],cnt++;
		if (cnt&1) {puts("NO"); return 0;}
	}
	puts("YES");
	rep(i,1,n+1) {
		rep(j,1,m+1) printf("%d ",a[i][j]);
		puts("");
			
	}
	return 0;
}