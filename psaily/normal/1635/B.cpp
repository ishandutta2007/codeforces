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
int a[N];
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		
		int n;
		scanf("%d",&n);
		FOR(i,1,n) scanf("%d",&a[i]);
		int r=0;
		FOR(i,2,n-1) {
			if(a[i]>a[i-1] && a[i]>a[i+1]) {
				a[i+1]=max(a[i],a[i+2]);
				++r;
			}
		}
		printf("%d\n",r);
		FOR(i,1,n) printf("%d%c",a[i]," \n"[i==n]);
	}
	
	return 0;
}