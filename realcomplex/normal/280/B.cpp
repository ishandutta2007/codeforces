#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<int, int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<int> arr;
vector<int> s;

int check(){
	s.clear();
	int mx = 0;
	for(auto x : arr){
		while(!s.empty() && s.back() < x)
			s.pop_back();
		if(!s.empty())mx = max(mx, x ^ s.back());
		s.push_back(x);
	}
	return mx;
}

int main(){
	fastIO;
	int n;
	cin >> n;
	int x;
	for(int i = 0 ; i < n; i ++ ){
		cin >> x;
		arr.push_back(x);
	}
	int v1 = check();
	reverse(arr.begin(), arr.end());
	v1 = max(v1, check());
	cout << v1 << "\n";
	return 0;
}