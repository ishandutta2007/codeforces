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

pp d[510];
int n, w, h;

typedef tuple<int,int,int,int> t4;
t4 rect[510];

bool check(int d){
	vector<int> looks;
	for(int i=0; i<n; ++i){
		int x, y; tie(x, y) = ::d[i];
		rect[i]=make_tuple(max(1, x-d), min(w, x+d), max(1, y-d), min(h, y+d));
		looks.pb(max(1, x-d-1));
		looks.pb(max(1, x-d));
		looks.pb(min(w, x+d));
		looks.pb(min(w, x+d+1));
	}
	looks.pb(1);
	looks.pb(w);
	sort(all(looks));
	looks.erase(unique(all(looks)), looks.end());
	int minx=w+1, maxx=-1;
	int miny=h+1, maxy=-1;
	for(int x:looks){
		vector<pp> gug;
		for(int i=0; i<n; ++i){
			int l, r, d, u;
			tie(l, r, d, u) = rect[i];
			if(x<l || r<x) continue;
			gug.eb(d, u);
		}
		if(gug.empty()){
			minx = min(minx, x);
			maxx = max(maxx, x);
			miny = 1; maxy = h;
			continue;
		}
		sort(all(gug));
		
		int min_y = 1;
		for(pp g:gug){
			if(g.x <= min_y && min_y <= g.y){
				min_y = g.y + 1;
			}
		}
		int max_y = h;
		sort(all(gug), [](const pp&a, const pp&b){return a.y>b.y; });
		for(pp g:gug){
			if(g.x <= max_y && max_y <= g.y){
				max_y = g.x - 1;
			}
		}
		if(min_y <= max_y){
			minx = min(minx, x);
			maxx = max(maxx, x);
			miny = min(miny, min_y);
			maxy = max(maxy, max_y);
		}
	}
	return maxx-minx <= 2LL*d && maxy-miny <= 2LL*d;
}

int main()
{
	read(w, h, n);
	for(int i=0; i<n; ++i){
		int x, y; read(x, y);
		d[i]={x, y};
	}
	int l=-1, r=int(1e9)+1;
	while(l+1 < r){
		int mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	printf("%d\n", r);
	return 0;
}