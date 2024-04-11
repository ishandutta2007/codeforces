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

const int maxn = 500 + 10;
LL a[maxn],
   b[maxn];
int prv[maxn],
	nxt[maxn],
	n, m;
vector<pair<int, char> > ans;

void naaa(void){
	cout << "NO" << endl;
	exit(0);
}

void remove(int id){
	prv[nxt[id]] = prv[id];
	if(~prv[id]) nxt[prv[id]] = nxt[id];
	return;
}

void merge(int st, int en){
	if(st >= en) naaa();
	if(en - st == 1) return;
	int id = max_element(a + st, a + en) - a;
	if(count(a + st, a + en, a[id]) == en - st) naaa();
	if(id == st){
		while(a[id] == a[id + 1]) id++;
		while(nxt[id] < en){
			ans.PB(MP(id, 'R'));
			remove(nxt[id]);
		}
		int tmp = 0;
		while(prv[id] >= st){
			ans.PB(MP(id - tmp, 'L')), tmp++;
			remove(prv[id]);
		}
	}
	else{
		int tmp = 0;
		while(prv[id] >= st){
			ans.PB(MP(id - tmp, 'L')), tmp++;
			remove(prv[id]);
		}
		while(nxt[id] < en){
			ans.PB(MP(id - tmp, 'R'));
			remove(nxt[id]);
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	iota(prv, prv + maxn, -1);
	iota(nxt, nxt + maxn, +1);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	for(int i = 0; i < m; i++)
		cin >> b[i];
	int ptr = n - 1;
	for(int i = m - 1; i >= 0; i--){
		int tmp = ptr;
		LL sum = 0;
		while(ptr >= 0 and sum < b[i]) sum += a[ptr--];
		if(sum != b[i])
			naaa();
		merge(ptr + 1, tmp + 1);
	}
	if(~ptr) naaa();
	cout << "YES" << '\n';
	for(auto pp : ans)
		cout << pp.L+1 << ' ' << pp.R << '\n';
	return 0;
}