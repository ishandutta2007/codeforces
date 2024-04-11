#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,n,a) for (int i=(n)-1;i>=(a);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define make_unique(x) { sort(all(x)); x.resize(unique(all(x))-x.begin()); }
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
mt19937 mrand(time(0));
typedef long long ll;
typedef long double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int inf=1<<30;
const int mod=1e9+7;
// head
const int N=1e6+5;
int n;
char s[N];

int main() {
	scanf("%d%s",&n,s+1);

	char *str=s;
	while (str[1]=='0'&&n) str++,n--;

	//debug(n);
	//rep(i,1,n+1) printf("%c",str[i]);
	//puts("");
	if (!n) {
		puts("0");
		return 0;
	}

	int p=1;
	while (str[p]!='0'&&p<=n) p++;
	if (p==n+1) {
		rep(i,1,n+1) printf("%c",str[i]);
		puts("");
		return 0;
	}

	vector<int> ans(n+1),a(n+1);
	rep(i,1,n+1) a[i]=ans[i]=str[i]-'0';
	auto cmp=[&](vector<int> &ans,vector<int> &a) {
		// rep(i,1,n+1) printf("%d",a[i]);
		// puts("");

		rep(i,1,n+1) {
			if (ans[i]>a[i]) return;
			else if (a[i]>ans[i]) {
				rep(j,1,n+1) ans[j]=a[j];
				return;
			}
		}
	};

	rep(k,0,p) {// [0,p-1]
		//rep(i,1,n+1) printf("%d",a[i]);
		//puts("");

		auto b=a;
		rep(i,1,n+1) if (a[i]&&k+i<=n) b[i+k]|=1;
		cmp(ans,b);
		
	}

	p=0;
	while (p<n&&ans[p]==0) p++;
	rep(i,p,n+1) printf("%d",ans[i]);
	puts("");
	return 0;
}