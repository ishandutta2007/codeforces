#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N=2e5+50;
const int Mod=1e9+7;
ll a[N];
int x[N],y[N],z[N];
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n;
		scanf("%d",&n);
		FOR(i,1,n) scanf("%lld",&a[i]);
		int r=0;
		DOR(i,n-2,1) {
			if(a[i+1]-a[n]<a[i]) {
				a[i]=a[i+1]-a[n];
				++r;x[r]=i;y[r]=i+1;z[r]=n;
			}
		}
		FOR(i,1,n-1) if(a[i]>a[i+1]) r=-1;
		printf("%d\n",r);
		FOR(i,1,r) printf("%d %d %d\n",x[i],y[i],z[i]);
	}
	return 0;
}