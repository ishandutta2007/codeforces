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
 
const int N=2050;
int n,T;
int a[N],pos[N];
vi ans;

void rev(int x) {
	reverse(a+1,a+1+x);
	rep(i,1,x+1) pos[a[i]]=i;
}

int main() {
	scanf("%d",&T);
	while (T--) {
		ans.clear();
		
		scanf("%d",&n);
		rep(i,1,n+1) scanf("%d",&a[i]),pos[a[i]]=i;
		
		bool ok=1;
		
		for (int i=n;i>=3;i-=2) {
			int a=i,b=i-1;
			if (pos[a]%2==0||pos[b]%2==1) {ok=0; break;}
			
			ans.pb(pos[a]),rev(pos[a]);
			ans.pb(pos[b]-1),rev(pos[b]-1);
			ans.pb(pos[b]+1),rev(pos[b]+1);
			ans.pb(3),rev(3);
			ans.pb(i),rev(i);
		}
		
		if (!ok) puts("-1");
		else {
			printf("%d\n",SZ(ans));
			if (SZ(ans)) {
				rep(i,0,SZ(ans)) printf("%d ",ans[i]);
				puts("");
			}
		}
	}
	return 0;	
}