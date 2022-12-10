//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 5e4 + 85 - 69;
vector<int> vec;
int n;
int a[maxn];
set<int> s;

int has(int val){
	while(val){
		val >>= 1;
		if(s.find(val) == s.end())
			return val;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		s.insert(a[i]);
	}
	while(sz(s)){
		int v = *s.rbegin();
		s.erase(v);
		int val = has(v);
		if(val) s.insert(val);
		else vec.PB(v);
	}
	for(auto val : vec)
		cout << val << ' ';
	cout << '\n';
	return 0;
}