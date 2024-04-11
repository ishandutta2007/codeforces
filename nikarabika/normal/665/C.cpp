//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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
bool mark[26];

char fre(int i){
	memset(mark, false, sizeof mark);
	if(i + 1 < sz(s))
		mark[s[i + 1] - 'a'] = true;
	mark[s[i - 1] - 'a'] = true;
	for(int i = 0; i < 26; i++)
		if(!mark[i])
			return i + 'a';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	for(int i = 1; i < sz(s); i++)
		if(s[i] == s[i - 1])
			s[i] = fre(i);
	cout << s;
	return 0;
}