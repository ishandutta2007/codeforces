#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = (int)2e5 + 9;

int b[N];
vector<int> bids[N];

int main(){
	fastIO;
	int n;
	cin >> n;
	int p, csh;
	for(int i = 0; i < n; i++ ){
		cin >> p >> csh;
		b[p] = csh;
		bids[p].push_back(csh);
	}
	set<pii> play;
	for(int i = 1; i <= n; i ++ ){
		if(b[i] > 0)play.insert(mp(b[i], i));
	}
	int q;
	cin >> q;
	int k, ix;
	for(int i = 0; i < q; i ++ ){
		cin >> k;
		vector<int> dt;
		for(int j = 0; j < k ; j ++ ){
			cin >> ix;
			dt.push_back(ix);
			play.erase(mp(b[ix], ix));
		}
		if(play.empty()){
			cout << "0 0\n";
		}
		else{
			auto it = play.end();
			-- it;
			int id;
			int lw;
			id = it -> se;
			if(play.size() == 1){
				lw = 0;
			}
			else{
				-- it;
				lw = it->fi;
			}
			lw = lower_bound(bids[id].begin(), bids[id].end(), lw) - bids[id].begin();
			cout << id << " " << bids[id][lw] << "\n";
		}
		for(auto p : dt){
			if(b[p] > 0)play.insert(mp(b[p], p));
		}
	}
	return 0;
}