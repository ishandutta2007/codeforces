//sobskdrbhvk
//remember the flying, the bird dies ):(
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

int com;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	set<string> s;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		s.insert(str);
	}
	for(int i = 0; i < m; i++){
		string str;
		cin >> str;
		if(s.find(str) != s.end())
			com++;
	}
	n -= com;
	m -= com;
	if(com & 1)
		cout << (n >= m ? "YES" : "NO");
	else
		cout << (m >= n ? "NO" : "YES");
	return 0;
}