#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second

#define p 1000000007

using namespace std;

typedef long long ll;

void f(){
	int n, x;
	cin >> n >> x;
	vpii blow;
	for(int i=0;i<n;i++){
		int v1, v2;
		cin >> v1 >> v2;
		blow.pb(mp(v1, v2));
	}
	int max_att = -1;
	int max_diff = -1;
	for(int i=0;i<n;i++){
		max_att = max(max_att, blow[i].fi);
		max_diff = max(max_diff, blow[i].fi - blow[i].se);
	}
	if(max_att >= x){
		cout << 1 << endl;
		return;
	}else{
		if(max_diff <= 0){
			cout << -1 << endl;
		}else{
			int ans = 1;
			x -= max_att;
			cout << (int) ceil((double) x / max_diff) + 1 << endl;
		}
	}
}
int main(){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		f();
	}
	return 0;
}