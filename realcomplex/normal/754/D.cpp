#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<int, int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
	fastIO;
	int n, k;
	cin >> n >> k;
	pii segm[n];
	vector<pii> seg;
	for(int i = 0 ; i < n; i ++ ){
		cin >> segm[i].fi >> segm[i].se;
		seg.push_back(segm[i]);
	}
	sort(segm, segm + n);
	multiset<int> ends;
	int answ = 0;
	int	li;
	for(int i = 0 ; i < n; i ++ ){
		ends.insert(segm[i].se);
		while(!ends.empty() && *ends.begin() < segm[i].fi){
			ends.erase(ends.begin());
		}
		while(ends.size() > k){
		    ends.erase(ends.begin());
		}
		if(ends.size() >= k){
			if(*ends.begin() - segm[i].fi + 1 >= answ){
				answ = *ends.begin() - segm[i].fi + 1;
				li = segm[i].fi;
			}
		}
	}
	cout << answ << "\n";
	if(answ == 0){
		for(int i = 1; i <= k ; i ++ ){
			cout << i << " ";
		}
		return 0;
	}
	int ri = li + answ - 1;
	for(int j = 0 ; j < seg.size(); j ++ ){
		if(seg[j].fi <= li && seg[j].se >= ri){
			if(k > 0){
				cout << j + 1 << " ";
				-- k;
			}
		}
	}
	return 0;
}