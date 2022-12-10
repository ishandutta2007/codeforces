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

set<int> st[2];
int n;
string s;
bool mark[1000 * 1000];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n
		>> s;
	for(int i = 0; i < n; i++)
		st[s[i]=='D'].insert(i);
	for(int i = 0; i < n and sz(st[0]) and sz(st[1]); i = (i + 1) % n) if(!mark[i]){
		int sid = s[i] != 'D';
		auto it = st[sid].lower_bound(i);
		if(it == st[sid].end()) it = st[sid].begin();
		mark[*it] = true;
		st[sid].erase(it);
	}
	if(sz(st[0]))
		cout << 'R';
	else
		cout << "D";
	return 0;
}