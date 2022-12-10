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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	stack<int> stc;
	cin >> s;
	for(int i = 0; i < sz(s); i++){
		if(sz(stc) and stc.top() == s[i])
			stc.pop();
		else
			stc.push(s[i]);
	}
	if(sz(stc))
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
	return 0;
}