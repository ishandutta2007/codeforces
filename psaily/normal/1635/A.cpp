#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N=1e5+50;
int a[N];
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		
		int n;
		scanf("%d",&n);
		int r=0;
		FOR(i,1,n) scanf("%d",&a[i]),r|=a[i];
		printf("%d\n",r);
	}
	
	return 0;
}