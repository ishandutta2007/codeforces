#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define SZ(x) ((int)x.size())
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define pb push_back
typedef long long ll;
typedef double db;
typedef vector<int> VI;

// head
int n,m;

int id(int x,int y) {
	return (x-1)*m+y;	
}

void solve() {
	scanf("%d%d",&n,&m);
	int x=1,y=1;
	ll res1=1,res2=1;
	while (x<n) {
		x++;
		res1+=id(x,y);
	}
	while (y<m) {
		y++;
		res1+=id(x,y);
	}
	x=y=1;
	while (y<m) {
		y++;
		res2+=id(x,y);
	}
	while (x<n) {
		x++;
		res2+=id(x,y);
	}
	printf("%lld\n",min(res1,res2));
}

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();	
	}
	return 0;	
}