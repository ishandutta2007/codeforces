#include <bits/stdc++.h>
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
typedef double db;
// head 

const int N=3e5+5;
int n,x;
int a[N];

int main() {
	int _;
	for (cin>>_;_;_--) {
		cin>>n>>x;
		map<int,int> mmap;
		rep(i,1,n+1) {
			scanf("%d",&a[i]),mmap[a[i]]++;
		}
		sort(a+1,a+1+n);
		int m=unique(a+1,a+1+n)-a-1;
		int res=0;
		per(i,m+1,1) {
			int v=a[i];
			if (v%x==0) {
				// bug(mmap[v]),debug(mmap[v/x]);
				int tmp=min(mmap[v],mmap[v/x]);
				// bug(v),debug(tmp);
				res+=tmp;
				mmap[v/x]-=tmp,mmap[v]-=tmp;
			}
		}
		printf("%d\n",n-res*2);
	}
	return 0;	
}