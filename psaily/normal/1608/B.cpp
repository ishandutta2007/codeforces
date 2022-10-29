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
typedef long double db;
// head 

const int N=1e5+5;
int n,m,_,a,b;
int p[N];

int main() {
	for (cin>>_;_;_--) {
		cin>>n>>a>>b;
		if (abs(a-b)>1||a+b>n-2) puts("-1");
		else {
			int l=1,r=n,cur=1;
			
			if (a==b-1) p[cur++]=r--;
			
			rep(i,1,min(a,b)+2) p[cur++]=l++,p[cur++]=r--;
			if (a==b+1) {
				per(i,r+1,l) p[cur++]=i;
			}else {
				cur--,r++;
				rep(i,l,r+1) p[cur++]=i;
			}	
			
			rep(i,1,n+1) printf("%d ",p[i]);\
			puts("");
		}
	}
	
	
	return 0;	
}