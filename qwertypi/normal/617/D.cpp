#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

bool check(vector<pair<int, int>> points){
	if(points[0].fi == points[1].fi){
		int l = min(points[0].se, points[1].se), r = max(points[0].se, points[1].se);
		if(r <= points[2].se || points[2].se <= l) return true;
	}
	return false;
}

int main(){
	vector<pair<int, int>> points;
	for(int i = 0; i < 3; i++){
		int x, y;
		cin >> x >> y;
		points.push_back({x, y});
	}
	if(points[0].fi == points[1].fi && points[1].fi == points[2].fi){
		cout << 1 << endl;
		return 0;
	}
	for(auto& p : points) swap(p.first, p.second);
	if(points[0].fi == points[1].fi && points[1].fi == points[2].fi){
		cout << 1 << endl;
		return 0;
	}
	for(auto& p : points) swap(p.first, p.second);
	if(check(points)){
		cout << 2 << endl;
		return 0;
	}
	swap(points[0], points[1]); swap(points[1], points[2]);
	if(check(points)){
		cout << 2 << endl;
		return 0;
	}
	swap(points[0], points[1]); swap(points[1], points[2]);
	if(check(points)){
		cout << 2 << endl;
		return 0;
	}
	swap(points[0], points[1]); swap(points[1], points[2]);
	for(auto& p : points) swap(p.first, p.second);
	if(check(points)){
		cout << 2 << endl;
		return 0;
	}
	swap(points[0], points[1]); swap(points[1], points[2]);
	if(check(points)){
		cout << 2 << endl;
		return 0;
	}
	swap(points[0], points[1]); swap(points[1], points[2]);
	if(check(points)){
		cout << 2 << endl;
		return 0;
	}
	swap(points[0], points[1]); swap(points[1], points[2]);
	for(auto& p : points) swap(p.first, p.second);
	cout << 3 << endl;
	return 0;
}