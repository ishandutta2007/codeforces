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

int T,n;
int a[N];

int main() {
	cin>>T;
	while (T--) {
		scanf("%d",&n);
		rep(i,1,n+1) scanf("%d",&a[i]);
		if (a[1]==1) {
			printf("%d ",n+1);
			rep(i,1,n+1) printf("%d%c",i," \n"[i==n]);
		}else if (a[n]==0) {
			rep(i,1,n+1) printf("%d ",i);
			printf("%d\n",n+1);
		}else {
			bool f=0;
			rep(i,1,n) if (!a[i]&&a[i+1]) {
				f=1;
				rep(j,1,n+1) {
					printf("%d%c",j," \n"[j==n]);
					if (j==i) printf("%d ",n+1);	
				}
				break;
			}
			if (!f) puts("-1");
		}	
	}
	
	return 0;	
}