#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
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
const int N=1e5+5;
int T,k;
int ans[N];

void pre() {
	for (int i=1;;i++) {
		int cnt=0,f=!(i%10==3);
		for (int x=i;x;x/=10) cnt+=x%10;
		if (cnt%3&&f) ans[++ans[0]]=i;
		if (ans[0]>=1000) break;
	}
	// rep(i,1,20+1) printf("%d ",ans[i]); puts("");	
}

int main() {
	cin>>T;
	pre();
	while (T--) {
		int k;
		scanf("%d",&k);
		printf("%d\n",ans[k]);	
	}
	return 0;	
}