#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 3123;

int cnt[N];

map<pii, int> ask;

int main(){
	fastIO;
	int n;
	cin >> n;
	ll a[n];
	int tid[n];
	int zer = 0;
	for(int i = 0 ;i < n; i ++ ){
		cin >> a[i];
		zer += (a[i] == 0);
	}
	sort(a, a + n);
	int id;
	for(int i = 0 ; i < n; i ++ ){
		id = lower_bound(a, a + n, a[i]) - a;
		tid[i] = id;
		cnt[id] ++ ;
	}
	int answ = 2;
	int curl;
	ll x1, x2, nx;
	for(int i = 0 ; i < n; i ++ ){
		for(int j = 0 ; j < n; j ++ ){
			if(i == j)
				continue;
			if(a[i] == 0 && a[j] == 0){
				answ = max(answ, zer);
				continue;
			}
			if(ask.count(mp(a[i],a[j]))){
				continue;
			}
			ask[mp(a[i],a[j])]=1;
			curl = 2;
			x1 = a[i];
			x2 = a[j];
			cnt[tid[i]] -- ;
			cnt[tid[j]] -- ;
			vector<int> rem;
			rem.push_back(tid[i]);
			rem.push_back(tid[j]);
			while(1){
				nx = x1 + x2;
				id = lower_bound(a, a + n, nx) - a;
				if(id >= n || a[id] != nx){
					break;
				}
				if(cnt[id] - 1 >= 0){
					cnt[id] -- ;
					rem.push_back(id);
					x1 = x2;
					x2 = nx;
					curl ++ ;
				}
				else{
					break;
				}
			}
			answ = max(answ, curl);
			for(auto x : rem)
				cnt[x] ++ ;
		}
	}
	cout << answ << "\n";
	return 0;
}