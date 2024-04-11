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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int ord[4] = {0, 1, 3, 2};
	char a[4];
	vector<char> vec1, vec2;
	for(int i = 0; i < 4; i++) cin >> a[i];
	for(int i = 0; i < 4; i++)
		if(a[ord[i]] != 'X')
			vec1.PB(a[ord[i]]);
	for(int i = 0; i < 4; i++) cin >> a[i];
	for(int i = 0; i < 4; i++)
		if(a[ord[i]] != 'X')
			vec2.PB(a[ord[i]]);
	rotate(vec1.begin(), find(all(vec1), 'A'), vec1.end());
	rotate(vec2.begin(), find(all(vec2), 'A'), vec2.end());
	if(vec1 == vec2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}