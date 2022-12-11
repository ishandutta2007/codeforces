#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll wait_time;
ll best_pos;

void upd(ll ntime, ll ps){
	if(ntime < wait_time){
		wait_time = ntime;
		best_pos = ps;
	}
}
ll calc(ll lf, ll rf){
	return rf - lf;
}

int main(){
	fastIO;
	wait_time = (ll)1e15;
	best_pos = -1;
	ll st, sf;
	ll req;
	int n;
	cin >> st >> sf >> req >> n;
	if(n==0){
		cout << st << "\n";
		return 0;
	}
	ll pos[n];
	for(int i = 0 ; i < n; i ++ )
		cin >> pos[i];
	ll en[n];
	en[0] = max(pos[0], st) + req;
	for(int i = 1; i < n; i ++ ){
		en[i] = max(pos[i], en[i-1]) + req;
	}
	for(int i = 0 ; i < n; i ++ ){
		if(en[i] + req <= sf && (i == n - 1 || pos[i] != pos[i + 1])){
			upd(calc(pos[i], en[i] + req), pos[i]);
		}
	}
	for(int i = 0 ; i < n; i ++ ){
		if((i == n - 1 || en[i] < pos[i + 1]) && en[i] + req <= sf){
			upd(calc(en[i], en[i] + req), en[i]);
		}
	}
	ll v = max(pos[0] - 1, st);
	if(v + req <= sf)upd(calc(pos[0] - 1, v + req), pos[0] - 1);
	ll shend;
	for(int i = 1; i < n; i ++ ){
		if(pos[i] - 1 > pos[i - 1]){
			shend = max(en[i-1], pos[i]-1) + req;
			if(shend <= sf)
				upd(calc(pos[i]-1, shend), pos[i] - 1);
		}
	}
	if(best_pos == -1)
		best_pos = st;
	cout << best_pos;
	return 0;
}