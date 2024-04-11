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

const int maxn = 100 + 85 - 69, maxsq = 2000;
string a, c;
int nxt[maxn][26],
	lst[maxn],
	lstsq[maxn],
	b, d;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> b >> d
		>> a >> c;
	for(int i = 0; i < sz(c); i++)
		if(find(all(a), c[i]) == a.end()){
			cout << 0;
			return 0;
		}

	memset(nxt, -1, sizeof nxt);
	for(int i = 0; i < sz(a); i++)
		for(int j = 0; j < 26; j++)
			for(int len = 0; len < sz(a); len++)
				if(a[(i + len) % sz(a)] == 'a' + j){
					nxt[i][j] = len + 1;
					break;
				}

	memset(lst, -1, sizeof lst);
	for(int st = 0; st < sz(a); st++)
		for(int i = 0; i < sz(c); i++)
			lst[st] += nxt[(st + lst[st] + 1) % sz(a)][c[i] - 'a'];

	for(int st = 0; st < sz(a); st++)
		for(int i = 0; i < maxsq; i++)
			lstsq[st] += lst[(st + lstsq[st]) % sz(a)] + 1;

	int pos = 0, cnt = 0;
	for(pos; pos + lstsq[pos % sz(a)] <= b * sz(a); pos += lstsq[pos % sz(a)], cnt += maxsq);
	for(pos; pos + lst[pos % sz(a)] + 1 <= b * sz(a); pos += lst[pos % sz(a)] + 1, cnt++);
	cout << cnt / d << endl;
	return 0;
}