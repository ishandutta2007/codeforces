#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define SZ(x) ((int)x.size())
#define pb push_back
#define all(x) x.begin(),x.end()
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long LL;
typedef double db;
typedef vector<int> VI;
const int inf=1<<30;
using PII = pair<int,int>;
const int N=2e5+5;

int n, m, p[N];
vector<int> v;
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i ++) scanf("%d", p+i);
	v.push_back(-1000000);
	for(int i = 1;i <= m;i ++){
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}
	v.push_back(n*1000);
	sort(v.begin(), v.end());
	vector<PII> tem;
	
	for(int i = 1;i <= n;i ++)
	{ 
		int pos = lower_bound(v.begin(), v.end(), (i-1)*100) - v.begin();
		int l = v[pos], r = v[pos-1];
		int len = min(l - (i-1)*100, (i-1)*100 - r);
		tem.push_back({(i-1)*100-len, p[i]});
		tem.push_back({(i-1)*100+len, -p[i]});
		//cout<<l<<' '<<r<<' '<<pos<<endl;
	} 
	sort(tem.begin(), tem.end());
	LL sum = 0, ans = 0;
	for(auto x : tem)
		sum += x.second, ans = max(ans, sum);
	cout<<ans<<endl;
 	return 0;	
}