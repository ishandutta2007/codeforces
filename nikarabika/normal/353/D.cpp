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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	deque<char> d;
	{
		string s;
		cin >> s;
		for(int i = 0; i < sz(s); i++)
			d.PB(s[i]);
	}
	while(sz(d) and d.front() == 'F')
		d.pop_front();
	while(sz(d) and d.back() == 'M')
		d.pop_back();
	int lans = 0,
		mcnt = 0;
	for(int i = 0; i < sz(d); i++)
		if(d[i] == 'M')
			mcnt++;
		else
			lans = max(lans + 1, mcnt);
	cout << lans << '\n';
	return 0;
}