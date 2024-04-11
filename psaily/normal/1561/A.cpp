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
const int N=1005;

int T;
int n,a[N];

int main() {
	cin>>T;
	while (T--) {
		scanf("%d",&n);
		rep(i,1,n+1) scanf("%d",&a[i]);
		
		for (int stp=1;;stp++) {
			int cnt=0;
			if (stp&1) {
				for (int j=1;j+1<=n;j+=2) if (a[j]>a[j+1]) swap(a[j],a[j+1]),cnt++;
			}else {
				for (int j=2;j+1<=n;j+=2) if (a[j]>a[j+1]) swap(a[j],a[j+1]),cnt++;
			}
			bool f=1;
			rep(i,1,n) if (a[i]>a[i+1]) {f=0; break;}
			if (!cnt&&f) {printf("%d\n",stp-1); break;}
		}	
	}
	
	
	return 0;	
}