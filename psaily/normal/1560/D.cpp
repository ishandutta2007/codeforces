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
const int N=1e5+5;
int T,n;
ll pw[65];
int a[20],b[20];

int main() {
	pw[0]=1;
	rep(i,1,64) pw[i]=pw[i-1]*2;
	scanf("%d",&T);
	while (T--) {
		int ans=30;
		scanf("%d",&n);
		rep(i,0,64) {
			int res=0;
			ll x=pw[i],y=n;
			a[0]=b[0]=0;
			while (x) a[++a[0]]=x%10,x/=10;
			while (y) b[++b[0]]=y%10,y/=10;
			int cur=b[0];
			for (int i=a[0];i;i--) {
				while (cur&&b[cur]!=a[i]) cur--,res++;
				if (!cur) res++;
				else cur--;
			}
			if (cur) res+=cur;
			ans=min(ans,res);
		}
		printf("%d\n",ans);
	}
	
	return 0;	
}