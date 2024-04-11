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
const db eps=1e-9;
int n,a,b;

struct seg {
	db x,y;
	bool operator < (const seg&_)const {
		// return y/x>_.y/_.x; 
		return y*_.x>_.y*x;
	}
};

db xx[N],yy[N];

void solve() {
	scanf("%d%d%d",&n,&a,&b);
	rep(i,1,n+1) scanf("%Lf",&xx[i]);
	rep(i,1,n+1) scanf("%Lf",&yy[i]);

	db x0=a,y0=b,x1=a,y1=b;
	multiset<seg> Seg;

	rep(i,1,n+1) {
		db p=xx[i],q=yy[i];

		Seg.insert({2*p,-2*q});

		x0-=p,y0+=q;
		x1+=p,y1-=q;

		while (x0<0) {
			auto sg=*Seg.begin();
			Seg.erase(Seg.begin());

			if (x0+sg.x>0) {
				db k=fabs(x0)/sg.x;

				Seg.insert({sg.x*(1-k),sg.y*(1-k)});
				y0+=k*sg.y;
				x0=0;

				break;

			} else {
				x0+=sg.x;
				y0+=sg.y;
			}
		}

		while (y1<0) {
			auto sg=*Seg.rbegin();
			Seg.erase(prev(Seg.end()));

			if (y1-sg.y>0) {
				db k=fabs(y1)/fabs(sg.y);

				Seg.insert({sg.x*(1-k),sg.y*(1-k)});
				x1-=k*sg.x;
				y1=0;

				break;

			} else {
				x1-=sg.x;
				y1-=sg.y;
			}
		}

		//bug(x0),debug(y0);
		//bug(x1),debug(y1);

		printf("%10Lf\n",x1);

	}


}

int main() {	
	int tt;
	scanf("%d",&tt);
	while (tt--) {
		solve();
	}	



	return 0;
}