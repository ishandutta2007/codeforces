#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void sub(){
	vector<pair<int, int>> employs;
	int n;
	ll s;
	cin >> n >> s;
	for(int i = 0; i < n; i++){
		int v1, v2;
		cin >> v1 >> v2;
		s -= v1;
		employs.push_back({v1, v2});
	}
	sort(employs.begin(), employs.end(), [](pair<int, int> A, pair<int, int> B){
		return A.first > B.first || (A.first == B.first && A.second > B.second);
	});
	int upper = 1000000000;
	int lower = 1;
	while(upper != lower){
		int mid = (upper + lower + 1) / 2;
		int left = (n + 1) / 2;
		ll needed = 0;
		for(auto i : employs){
			if(i.second < mid){
				continue;
			}
			needed += max(0, mid - i.first);
			left--;
			if(left == 0)
				break;
		}
		if(left != 0 || s < needed)
			upper = mid - 1;
		else
			lower = mid;
	}
	cout << lower << endl;
}

int main(){
	int q;
	cin >> q;
	while(q--){
		sub();
	}
	return 0;
}