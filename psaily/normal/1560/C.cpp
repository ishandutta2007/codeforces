#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
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
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&k);
		int sq=sqrt(k);
		if (sq*sq==k) printf("%d %d\n",sq,1);
		else {
			sq++;
			int tot=sq*sq;
			tot-=k,tot++;
			if (tot<=sq) printf("%d %d\n",sq,tot);
			else {
				tot-=sq,tot++;
				printf("%d %d\n",sq-tot+1,sq);
			}
		}
	}
	return 0;	
}