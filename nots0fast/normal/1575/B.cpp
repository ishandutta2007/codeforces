
#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")


#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long
#define lll __int128
#define pb(a) push_back(a)
#define mt make_tuple
typedef  double ld;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10, 18);
ll modulo = pow(10,9) + 7;

#define M_PI acos(-1.0)

ld todeg(ld a){
	return a*180/M_PI;
}

void fix(ld& lef, ld& rig){
	if(rig < lef){
		swap(lef, rig);
	}
	if(rig-lef > M_PI){
		lef+=2*M_PI;
		swap(lef, rig);
	}
	while((lef+rig)/2 > M_PI){
		lef-=2*M_PI;
		rig-=2*M_PI;
	}
	while((lef+rig)/2 < -M_PI){
		lef+=2*M_PI;
		rig+=2*M_PI;
	}
}

void pointOnCircle(ld xc, ld yc, ld x, ld y, ld r){
	assert(abs(sqrt((x-xc)*(x-xc) + (y-yc)*(y-yc)) - r) <= 1e-4);
}

void deal(){
	ll n, need;
	cin>>n>>need;
	vector<pair<ll,ll> > arr(n);
	fori(n){
		cin>>arr[i].ff>>arr[i].ss;
	}
	ld lo = 0, hi = 2e5;
	while((hi - lo) / max(1.0, hi) > 1e-4){
		ld mid = (lo+hi)/2;
		ld r = mid;
		vector<pair<ld, ll> > all;
	//	cout<<"we checking radius "<<mid<<endl;
		forj(n){
			if(arr[j].ss * arr[j].ss + arr[j].ff * arr[j].ff > 4*r*r){
				continue;
			}
			ld lef,rig;
			ld x1 = arr[j].ff, y1 = arr[j].ss;
			if(x1 != 0){
				// (x - x1)^2 + (y-y1)^2 = r*r
				// x^2 + y^2 = r*r
				// - 2*x*x1 + x1^2 - 2*y*y1 + y1^2 = 0
				// x = (y1^2 + x1^2 - 2*y*y1)/(2*x1)
				// x = sqrt(r*r - y*y)
				// r*r-y*y = ( (y1^2 + x1^2 - 2*y*y1)/(2*x1) ) ^ 2
				// (r*r - y*y) * 4*x1*x1 = (y1^2 + x1^2 - 2*y*y1)^2
				// let val1 = y1*y1 + x1*x1
				// let val2 = 2*y1
				ld val1 = y1*y1 + x1*x1;
				ld val2 = 2*y1;
 				// (r*r - y*y) * 4*x1^2 = (val1- val2*y)^2
				// (-4*x1^2 - val2^2 ) *y*y  + 2*val1*val2 * y
				// - val1^2 + 4*x1^2 * r^2 = 0
				ld a = -4*x1*x1 - val2*val2;
				ld b = 2*val1*val2;
				ld c = -val1*val1 + 4*x1*x1*r*r;
				ld D = b*b - 4*a*c;
				ld kok = sqrt(D);
				ld ya = (-b+kok)/(2*a), yb = (-b - kok)/(2*a);
				ld xa = (y1*y1 + x1*x1 - 2*ya*y1)/(2*x1);
				ld xb = (y1*y1 + x1*x1 - 2*yb*y1)/(2*x1);
				
				/*
				pointOnCircle(xa, ya, 0, 0, r);
				pointOnCircle(xa, ya, x1, y1, r);
				pointOnCircle(xb, yb, 0, 0, r);
				pointOnCircle(xb, yb, x1, y1, r);
				*/
				
				lef = atan2(ya, xa);
				rig = atan2(yb, xb);
				fix(lef, rig);
				
				/*
				pointOnCircle(r*cos(lef), r*sin(lef), 0, 0, r);
				pointOnCircle(r*cos(lef), r*sin(lef), x1, y1, r);
				pointOnCircle(r*cos(rig), r*sin(rig), 0, 0, r);
				pointOnCircle(r*cos(rig), r*sin(rig), x1, y1, r);
				*/
			}
			else{
				if(y1!=0){
					ld val1 = x1*x1 + y1*y1;
					ld val2 = 2*x1;
					ld a = -4*y1*y1 - val2*val2;
					ld b = 2*val1*val2;
					ld c = -val1*val1 + 4*y1*y1*r*r;
					ld D = b*b - 4*a*c;
					ld kok = sqrt(D);
					ld xa = (-b+kok)/(2*a), xb = (-b - kok)/(2*a);
					ld ya = (y1*y1 + x1*x1 - 2*xa*x1)/(2*y1);
					ld yb = (y1*y1 + x1*x1 - 2*xb*x1)/(2*y1);
					lef = atan2(ya, xa);
					rig = atan2(yb, xb);
					
					/*
					pointOnCircle(xa, ya, 0, 0, r);
					pointOnCircle(xa, ya, x1, y1, r);
					pointOnCircle(xb, yb, 0, 0, r);
					pointOnCircle(xb, yb, x1, y1, r);
					*/
					
					fix(lef, rig);
				}
				else{
					lef = 0, rig = 2*M_PI;
				}
			}
			
		//	cout<<"lef rig came out as "<<todeg(lef)<<" "<<todeg(rig)<<endl;
			for(ll k = -1; k<=1; k++){
				all.pb(mp(lef+2*k*M_PI, 1));
				all.pb(mp(rig+2*k*M_PI, -1));
			}
		}
		sort(all.begin(), all.end());
		ll mx = 0;
		ll s = 0;
		for(auto& el : all){
			s+=el.ss;
			mx = max(mx, s);
		}
		if(mx >= need){
			hi = mid;
		}
		else{
			lo = mid;
		}
	}
	cout<<setp(13)<<(lo+hi)/2;
}
 

int main()  {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}