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

string s;
bool mark[1000000+1];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> s;
	s = 'x' + s;
	mark[0] = mark[sz(s)] = true;
	for(int i = 1; i < sz(s); i++)
		if(s[i] == '<' and mark[i - 1])
			mark[i] = true;
	for(int i = sz(s) -1 ; i >= 0; i--)
		if(s[i] == '>' and mark[i + 1])
			mark[i] = true;
	int ans = 0;
	for(int i =1; i < sz(s); i++)
		ans += mark[i];
	cout << ans << endl;
	return 0;
}