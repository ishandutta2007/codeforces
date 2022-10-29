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
const int N=2e5+5;

int T;
int a,b,k1,k2;
bool mark[N];
vi ans;

void add(int x) {
	if (!mark[x]) {
		ans.pb(x);
		mark[x]=1;
	}
}

void solve(int t) {
	rep(x,0,min(t,k1)+1) {
		if (x+k2-t>=0) {
			add(k1+t-2*x);
		}
	}
}

int main() {
	cin>>T;
	while (T--) {
		rep(i,0,SZ(ans)) mark[ans[i]]=0;
		ans.clear();
		
		scanf("%d%d",&a,&b);
		int tot=a+b;
		k1=(tot+1)/2,k2=tot-k1;
		solve(a); solve(b);
		sort(all(ans));
		printf("%d\n",SZ(ans));
		rep(i,0,SZ(ans)) printf("%d ",ans[i]); puts("");
	}
	return 0;	
}