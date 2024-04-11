#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(12)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define fork(v) for(int k=0; k<v; k++)
#define forz(v) for(int z=0; z<v; z++)
#define ll long long
#define pb(a) push_back(a)
#define mt make_tuple
// #define cout out
// #define cin in
#define ld long double
ll inf = 2*pow(10, 9);
ll modulo = 998244353 ;
double eps = 1e-10;
ifstream in;
ofstream out;

struct line{
	ll k, b;
	line(){
		
	}
	line(ll k1, ll b1){
		k = k1, b = b1;
	}
};

struct srt{
	const bool operator() (const ll& a,const ll& b ) const{
		return a > b;
	}	
};

void merge(ld& a1, ld& b1, ld a2, ld b2){
	a1 = min(a1, a2);
	b1 = max(b1, b2);
}

ld sect(line& a1, line& a2){
	ld k1 = a1.k, b1 = a1.b, k2 = a2.k, b2 = a2.b;
	
	// k1 * x + b1 = y
	// k2 * x + b2 = y
	
	// (k2 - k1) * x + (b2 - b1) = 0
	
	// x = (b1 - b2) / (k2 - k1)
	 
	ld x =  (b1 - b2) / (k2 - k1);
	
	return x;
}

struct minHull{
	map< ll, tuple<line, ld, ld> , srt  > all;
	map<ld , line> ranges;
	
	void insert(line cur){
		if(all.empty()){
			all.insert(mp(cur.k, mt(cur, -inf, inf)));
			ranges.insert(mp(-inf, cur));
			return;
		}
		
		ld lef = inf, rig = -inf;
		
		auto it = all.lower_bound(cur.k);
		// k-si verilmish duz xettin k-sindan kicik beraber olan ilk duz xett
		
		if(it != all.end() && (*it).ff == cur.k){
			auto[line2, a2, b2] = (*it).ss;
			if(line2.b <= cur.b){
				return;
			}
			else{
				auto itn = it;
				++itn;
				
				merge(lef, rig, a2, b2);
				ranges.erase(a2);
				all.erase(it);
				
				it = itn;
			}
		}
		
		
		if(it == all.end()){
			rig = inf;
		}
		while(it != all.end()){
			auto itn = it;
			++itn;
			
			auto& [line2, l2, r2] = (*it).ss;
			
			ld pt = sect(cur, line2);
			
			if(pt >= r2){
				merge(lef, rig, l2, r2);
				ranges.erase(l2);
				all.erase(it);
				it = itn;
			}
			else{ 
				if(pt > l2){
					merge(lef, rig, l2, pt);
					ranges.erase(l2);
					l2 = pt;
					ranges[l2] = line2;
				}
				break;
			}
		}
		
		
		
		
		if(it == all.begin()){
			lef = -inf;
		}
		while(it!=all.begin()){
			--it;
			auto& [line2, l2, r2] = (*it).ss;
		
			ld pt = sect(cur, line2);
			
		//	cout<<"we are here point is "<<pt<<endl;
			
			if(pt <= l2){
				merge(lef, rig, l2, r2);
				auto ita = it;
				++ita;
				ranges.erase(l2);
				all.erase(it);
				it = ita;
			}
			else{
				if(pt < r2){
					merge(lef, rig, pt, r2);
					r2 = pt;
				}
				break;
			}
		}
		
		
		if(lef < rig){
			all.insert(mp(cur.k, mt(cur, lef, rig)));
			ranges.insert(mp(lef, cur));
		}
	}
	
	ll que(ll x){
		// en azi bir duz xett var
		auto it = ranges.upper_bound(x);
		--it;
		auto& ln = (*it).ss;
		return ln.k * x + ln.b;
	}
	
	void display(){
		cout<<"lines sorted by k "<<endl;
		for(auto& el : all){
			auto [ln, l, r] = el.ss;
			cout<<"range "<<l<<" "<<r<<" line.K "<<ln.k<<"   line.B "<<ln.b<<endl;
		}
	}
};


#define MAX 100'100

ll dp[MAX];
vector<ll> g[MAX];
ll as[MAX];
ll bs[MAX];

void dfs(minHull& cur,ll hd, ll pr){
      for(auto& hr : g[hd]){
            if(hr == pr){
                  continue;
            }
            minHull yen;
            dfs(yen, hr, hd);
            if(cur.all.size() < yen.all.size()){
                  swap(cur, yen);
            }
            for(auto& el : yen.all){
                  line ln = get<0>(el.ss);
                  cur.insert(ln);
            }
      }
      if(!cur.all.empty()){
            dp[hd] = cur.que(as[hd]);
      }
      cur.insert(line(bs[hd], dp[hd]));
}

void deal(){
	ll n;
      cin>>n;
      fori(n){
            cin>>as[i];
      }
      fori(n){
            cin>>bs[i];
      }
      fori(n-1){
            ll x, y;
            cin>>x>>y;
            --x, --y;
            g[x].pb(y);
            g[y].pb(x);
      }
      minHull cur;
      dfs(cur, 0, -1);
      fori(n){
            cout<<dp[i]<<' ';
      }
      
}
    

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    deal();
}