#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second

const int N=1e6+50;

void solve() {
	int x,y;
	scanf("%d%d",&x,&y);
	int r=0;
	if(x==0 && y==0) r=0;
	else if(int(sqrt(x*x+y*y))*int(sqrt(x*x+y*y))==x*x+y*y) r=1;
	else r=2;
	printf("%d\n",r);
}
int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) {
		solve();
	}
	return 0;
}