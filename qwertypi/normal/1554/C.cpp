#include <bits/stdc++.h>
#define int long long
using namespace std;

pair<int, int> f(int x, int d){
	return {x / d * d, x / d * d + d - 1};
}

int32_t main(){
	int t;
	cin >> t;
	for(int iter = 0; iter < t; iter++){
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> segments;
		for(int i = m; i != -1; i -= (i + 1) & -(i + 1)){
			segments.push_back(f(i ^ n, (i + 1) & -(i + 1)));
		}
		segments.push_back({-1, -1});
		sort(segments.begin(), segments.end());
		bool done = false;
		for(int i = 0; i < (int) segments.size() - 1; i++){
			if(segments[i].second + 1 != segments[i + 1].first){
				cout << segments[i].second + 1 << endl;
				done = true;
				break;
			}
		}
		if(!done){
			cout << segments[(int) segments.size() - 1].second + 1 << endl;
		}
	}
}