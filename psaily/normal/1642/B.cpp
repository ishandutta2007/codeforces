#include <bits/stdc++.h>
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

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;
// head 

const int N=3e5+5;
int n;
int a[N];
int ans=0;

int main() {
	int _;
	for (cin>>_;_;_--) {
		cin>>n;
		map<int,bool> cnt;
		int res=0;
		rep(i,1,n+1) scanf("%d",&a[i]);
		rep(i,1,n+1) {
			if (cnt[a[i]]) continue;
			cnt[a[i]]=1,res++;	
		}
		
		rep(i,1,res+1) printf("%d ",res);
		rep(i,res+1,n+1) printf("%d ",i);
		puts("");
		
	}
	return 0;	
}