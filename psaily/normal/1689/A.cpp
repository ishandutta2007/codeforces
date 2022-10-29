#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--) 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x.begin(),x.end())
#define SZ(x) ((int)x.size())
#define make_unique(x) { sort(all(x)); x.resize(unique(all(x))-x.begin()); }
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
mt19937 mrand(time(0));
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int mod=998244353,inf=1<<30;
// head

char a[100010],b[100010];
int k;

void solve() {
	// puts("!!!");
	int n,m;
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s%s",a,b);
	sort(a,a+n);
	sort(b,b+m);
	int cura=0,curb=0,cnt=0;
	while (cura<n&&curb<m) {
		if (cnt==-k||(b[curb]>a[cura]&&cnt<k)) {
			printf("%c",a[cura++]);
			if (cnt>=0) cnt++;
			else cnt=1;
		} else {
			printf("%c",b[curb++]);
			if (cnt<=0) cnt--;
			else cnt=-1;
		}
	}
	puts("");
}
int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}	
	return 0;
}