#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll absolute(ll x){
	return max(x, -x);
}

struct Eater{
	ll sl;
	ll ai;
	ll bi;
	bool operator< (Eater N){
		return absolute(ai - bi) < absolute(N.ai - N.bi); 
	}
	
};

int main(){
	fastIO;
	int n;
	ll s;
	cin >> n >> s;
	ll eat[n];
	ll a[n];
	ll b[n];
	vector<Eater> fir, sec;
	ll ta = 0, tb = 0;
	for(int i = 0 ; i < n; i ++ ){
		cin >> eat[i] >> a[i] >> b[i];
		if(a[i] >= b[i]){
			ta += eat[i];
			fir.push_back({eat[i], a[i], b[i]});
		}
		else{
			tb += eat[i];
			sec.push_back({eat[i], a[i], b[i]});
		}
	}
	ll ra = ta % s;
	ll rb = tb % s;
	bool sol = (ra + rb <= s);
	ll wil;
	ll total = 0;
	vector<Eater> remains;
	sort(fir.begin(), fir.end());
	sort(sec.begin(), sec.end());
	ll rem;
	for(Eater x : fir){
		rem = min(ra, x.sl);
		if(rem == 0){
			total += x.sl * x.ai;
		}
		else{
			total += (x.sl - rem) * x.ai;
			remains.push_back({rem, x.ai, x.bi});
			ra -= rem;
		}
	}
	for(Eater x : sec){
		rem = min(rb, x.sl);
		if(rem == 0){
			total += x.sl * x.bi;
		}
		else{
			total += (x.sl - rem) * x.bi;
			remains.push_back({rem, x.ai, x.bi});
			rb -= rem;
		}
	}
	if(!sol){
		for(auto x : remains){
			total += x.sl * max(x.ai, x.bi);
		}
	}
	else{
		ll t1 = 0, t2 = 0;
		for(auto x : remains){
			t1 += x.sl * x.ai;
			t2 += x.sl * x.bi;
		}
		total += max(t1, t2);
	}
	cout << total << "\n";
	return 0;
}