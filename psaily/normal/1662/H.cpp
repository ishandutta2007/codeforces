#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define SZ(x) ((int)x.size())
#define pb push_back
#define all(x) x.begin(),x.end()
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef double db;
typedef vector<int> VI;
const int inf=1<<30;

const int N=2e5+5;
int n,x,a[N];
ll ans;
set<int>st;
void chk(int a)
{
	int sqr=sqrt(a);
	for(int i=1;i<=sqr;i++)
	if(a%i==0)
		st.insert(i),
	st.insert(a/i);
}
int main() {
	 
	int _;
	for (scanf("%d",&_);_;_--) {
		int n,m;
		scanf("%d%d",&n,&m);
		st.clear();
		chk(__gcd(n-1,m-1));
		
		chk(__gcd(n,m-2));
			chk(__gcd(n-2,m));
				chk(__gcd(__gcd(n,m-1),n-2));
					swap(n,m);
				chk(__gcd(__gcd(n,m-1),n-2));
		printf("%d",(int)st.size());
		for(auto x:st)
			printf(" %d",x);
		puts("");
	}
	return 0;	
}