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
const int N=2e5+5;
const int M=2*N;

int n,m,T;
char str[105];

int main() {
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		scanf("%s",str+1);
		rep(i,1,n+1) {
			if (str[i]=='U') printf("D");
			else if (str[i]=='D') printf("U");
			else printf("%c",str[i]);
		}
		puts("");
	}
	
	return 0;	
}