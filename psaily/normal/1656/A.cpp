#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
#define fi first
#define se second

const int N=4e5+50;

int a[N];
void solve() {
	int n;
	scanf("%d",&n);
	int p=1,q=1;
	FOR(i,1,n) scanf("%d",&a[i]); 
	FOR(i,2,n) if(a[i]>a[p]) p=i;
	FOR(i,2,n) if(a[i]<a[q]) q=i;
	printf("%d %d\n",q,p);
}
int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) {
		solve();
	}
	return 0;
}