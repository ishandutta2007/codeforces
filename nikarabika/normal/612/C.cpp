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
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))

int a[8] = {'(', ')', '[', ']', '{', '}', '<', '>'};
int match[1000];
string s;
stack<char> st;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 0; i < 8; i++)
		match[a[i]] = a[i ^ 1];
	cin >> s;
	int ans = 0;
	for(int i = 0; i < sz(s); i++){
		if(match[s[i]] > s[i])
			st.push(s[i]);
		else if(!sz(st)){
			cout << "Impossible" << endl;
			return 0;
		}
		else
			ans += (match[s[i]] != st.top()), st.pop();
	}
	if(st.size()){
		cout << "Impossible" << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}