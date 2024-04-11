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
	cin >> s;
	int A = find(all(s), '+') - s.begin(),
		B = find(all(s), '=') - s.begin() - A - 1,
		C = sz(s) - 2 - (A + B);
	if(A + B == C){
		cout << s << endl;
		return 0;
	}
	if(A > 1 and A + B - 1 == C + 1){
		rotate(s.begin(), s.begin() + 1, s.end());
		cout << s << endl;
		return 0;
	}
	if(C > 1 and A + B + 1 == C - 1){
		rotate(s.begin(), s.end() - 1, s.end());
		cout << s << endl;
		return 0;
	}
	if(B > 1 and A + B - 1 == C + 1){
		for(int i = 0; i < A; i++)
			cout << '|';
		cout << "+";
		for(int i = 1; i < B; i++)
			cout << '|';
		cout << "=";
		for(int i = 0; i <= C; i++)
			cout << '|';
		cout << endl;
		return 0;
	}
	cout << "Impossible" << endl;
	return 0;
}