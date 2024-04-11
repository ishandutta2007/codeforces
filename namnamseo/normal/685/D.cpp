#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

int n, k;

struct Event {
	int x;
	int y;
	int df;
};
Event ev[200010];
int en;

int yp[200010];
int ypn;

ll cnt[200010];

int lev[200010];
int lst[200010];

int main()
{
	read(n, k); --k;
	for(int i=1; i<=n; ++i){
		int x, y; read(x, y);
		ev[en].x = x - k;
		ev[en].y = y - k;
		ev[en].df = 1;
		++en;
		ev[en].x = x + 1;
		ev[en].y = y - k;
		ev[en].df = -1;
		++en;
		yp[ypn++] = y - k;
		yp[ypn++] = y + 1;
	}
	sort(ev, ev+en, [&](const auto& a, const auto& b){ return a.x<b.x; });
	sort(yp, yp+ypn);
	ypn=unique(yp, yp+ypn)-yp;
	
	for(int ei=0; ei<en; ++ei){
		int x=ev[ei].x;
		int y=ev[ei].y;
		int df=ev[ei].df;
		int yl=lower_bound(yp, yp+ypn, y)-yp;
		int yr=lower_bound(yp, yp+ypn, y+k+1)-yp;
		for(int j=yl; j<yr; ++j){
			if(lev[j]){
				cnt[lev[j]] += (x-lst[j])*1ll*(yp[j+1]-yp[j]);
			}
			lev[j] += df;
			lst[j]=x;
		}
	}
	
	for(int i=1; i<=n; ++i) printf("%lld ", cnt[i]);
	return 0;
}