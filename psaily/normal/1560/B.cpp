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
 
typedef unsigned long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<long long,int> pli;
typedef double db;
// head
 
const int mod=998244353;
const int N=1e5+5;
int T,k;

int main() {
	cin>>T;
	while (T--) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int n=2*abs(a-b);
		if (n<max(a,b)) puts("-1");
		else {
			if (c>n) puts("-1");
			else printf("%d\n",(c-1+n/2)%n+1);
		}
	}

	return 0;	
}