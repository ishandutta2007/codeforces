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

const int maxn = 2e5;
int t[maxn],
	badcnt[maxn],
	n, ans;
vector<int> bad;

bool check(int idx){
	if(idx + 1 >= n or idx < 0)
		return true;
	if(idx & 1)
		return t[idx] > t[idx + 1];
	return t[idx] < t[idx + 1];
}

int BAD(int st, int en){
	if(st > en) return 0;
	return (st == 0) ? badcnt[en] : badcnt[en] - badcnt[st - 1];
}

bool check2(int i, int j){
	if(BAD(0, i - 2) + BAD(i + 1, j - 2) + BAD(j + 1, n - 1) > 0)
		return false;
	return check(i - 1) and check(i) and check(j - 1) and check(j);
}

void find_ans(int id, int ug = -1){
	for(int i = 0; i < n; i++) if(i != id and i != ug){// and t[min(id, i)] < t[max(id, i)]){
		swap(t[i], t[id]);
		ans += check2(min(i, id), max(i, id));
		swap(t[i], t[id]);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> t[i];
	for(int i = 0; i + 1 < n; i++)
		if(!check(i))
			bad.PB(i), badcnt[i] = 1;
	for(int i = 1; i <= n; i++)
		badcnt[i] += badcnt[i - 1];
	find_ans(bad[0]);
	find_ans(bad[0] + 1, bad[0]);
	cout << ans << endl;
	return 0;
}