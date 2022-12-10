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

const int maxn = 200 * 1000;
LL ans[maxn],
   d[maxn],
   t[maxn],
   n, b, lastpop;
queue<int> Q;

void process(LL tim){
	while(sz(Q) and max(t[Q.front()], lastpop) + d[Q.front()] <= tim){
		ans[Q.front()] = max(t[Q.front()], lastpop) + d[Q.front()];
		lastpop = ans[Q.front()];
		Q.pop();
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> b;
	for(int i = 0; i < n; i++){
		cin >> t[i] >> d[i];
		process(t[i]);
		if(sz(Q) > b)
			ans[i] = -1;
		else
			Q.push(i);
	}
	process(1000LL * 1000 * 1000 * 1000 * 1000 * 1000);
	for(int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}