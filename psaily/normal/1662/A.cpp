#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define SZ(x) ((int)x.size())
#define pb push_back
#define all(x) x.begin(),x.end()
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef double db;
typedef vector<int> VI;
const int inf=1<<30;

const int N=2e5+5;
int n,x,a[N];
ll ans;

int main() {
	 
	int _;
	for (scanf("%d",&_);_;_--) {
		vector<int>vis(11);
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			vis[b]=max(vis[b],a);
		}
		int f=1;
		int sum=0;
		for(int i=1;i<=10;i++){
			if(!vis[i])f=0;
			else sum+=vis[i];
		}
		if(f)
			printf("%d\n",sum);
		else puts("MOREPROBLEMS");
	}
	return 0;	
}