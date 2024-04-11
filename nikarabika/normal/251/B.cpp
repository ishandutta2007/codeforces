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

const int maxn = 100 + 10;
int p[maxn],
	s[maxn],
	perm[maxn][maxn],
	n, k;

bool equal(int id){
	for(int i = 0; i < n; i++)
		if(s[i] ^ perm[id][i])
			return false;
	return true;
}

void func(int pos = k){
	if(equal(pos)){
		if((pos & 1) or pos == k) return;
		if(pos == k - 1 and pos){
			for(int i = 0; i < n; i++)
				perm[k + 1][p[i]] = perm[k][i];
			if(equal(k + 1)) return;
		}
		cout << "YES" << endl;
		exit(0);
		return;
	}
	if(pos == 0)
		return;
	for(int i = 0; i < n; i++)
		perm[pos - 1][i] = perm[pos][p[i]];
	return func(pos - 1);
}

void cnuf(int pos = k){
	if(equal(pos)){
		if((pos & 1) or pos == k) return;
		if(pos == k - 1 and pos){
			for(int i = 0; i < n; i++)
				perm[k + 1][i] = perm[k][p[i]];
			if(equal(k + 1)) return;
		}
		cout << "YES" << endl;
		exit(0);
		return;
	}
	if(pos == 0)
		return;
	for(int i = 0; i < n; i++)
		perm[pos - 1][p[i]] = perm[pos][i];
	return cnuf(pos - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> p[i], p[i]--;
	for(int i = 0; i < n; i++)
		cin >> s[i], s[i]--;
	iota(perm[k], perm[k] + n, 0);
	func();
	cnuf();
	cout << "NO" << endl;
	return 0;
}