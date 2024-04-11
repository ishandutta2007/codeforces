#include <bits/stdc++.h>
#define inf (1LL << 60)
#define int long long
using namespace std;

vector<pair<int, int>> vp;

long double ans = -1;
int best[4] = {0, 0, 0, 0};

long double euc(pair<int, int> A, pair<int, int> B){
	return sqrt((A.first - B.first) * (A.first - B.first) + (B.second - A.second) * (B.second - A.second));
}

void check(int a, int b, int c, int d){
	long double res = 0;
	res += euc(vp[a], vp[b]);
	res += euc(vp[b], vp[c]);
	res += euc(vp[c], vp[d]);
	if(res > ans){
		ans = res;
		best[0] = a, best[1] = b, best[2] = c, best[3] = d;
	}
}

int X, Y;
bool in(int x, int y){
	return (0 <= x && x <= X && 0 <= y && y <= Y);
}
int32_t main(){
	int a, b;
	cin >> a >> b;
	X = a, Y = b;
	set<pair<int, int>> S;
	for(int i = 0; i <= 1; i++){
		for(int j = 0; j <= 1; j++){
			if(in(0 + i, 0 + j)) S.insert({0 + i, 0 + j});
			if(in(a - i, 0 + j)) S.insert({a - i, 0 + j});
			if(in(0 + i, b - j)) S.insert({0 + i, b - j});
			if(in(a - i, b - j)) S.insert({a - i, b - j});
		}
	}
	for(auto i : S){
		vp.push_back(i);
	}
	int n = vp.size();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int x = 0; x < n; x++){
				for(int y = 0; y < n; y++){
					set<int> S;
					S.insert(i); S.insert(j); S.insert(x); S.insert(y);
					if(S.size() == 4){
						check(i, j, x, y);
					}
				}
			}
		}
	}
	// cout << ans << endl;
	for(int i = 0; i < 4; i++){
		cout << vp[best[i]].first << ' ' << vp[best[i]].second << endl;
	}
	return 0;
}