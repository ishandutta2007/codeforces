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

const int maxn =  1000 + 10;
int a[maxn],
	b[maxn];
bool mark[maxn];
int n;
vector<int> dif;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		if (a[i] != b[i])
			dif.PB(i);
	if (sz(dif) != 1 and sz(dif) != 2)
		assert(0);
	vector<int> vec;
	if (sz(dif) == 2) {
		for (int i = 0; i < n; i++) {
			if (i == dif[1])
				vec.PB(b[i]);
			else
				vec.PB(a[i]);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++)
				if (vec[i] == vec[j]) {
					vec[dif[0]] = b[dif[0]];
					vec[dif[1]] = a[dif[1]];
					break;
				}
		}
		for (int i = 0; i < n; i++)
			cout << vec[i] << ' ';
		cout << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i])
			vec.PB(a[i]), mark[a[i]-1] = true;
		else
			vec.PB(-1);
	}
	mark[a[dif[0]] - 1] = mark[b[dif[0]]-1] = true;
	int val = find(mark, mark + n, 0) - mark + 1;
	vec[dif[0]] = val;
	for (int i = 0; i < n; i++)
		cout << vec[i] << ' ';
	return 0;
}