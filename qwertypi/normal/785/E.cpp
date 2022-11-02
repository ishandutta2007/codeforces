#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define mp make_pair
using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> OST;

const int N = 200001;

OST bit[N];

void insert(int x, int y)
{
	for(int i = x; i < N; i += i & -i)
		bit[i].insert(mp(y, x));
}

void remove(int x, int y)
{
	for(int i = x; i < N; i += i & -i)
		bit[i].erase(mp(y, x));
}

int query(int x, int y)
{
	int ans = 0;
	for(int i = x; i > 0; i -= i & -i)
		ans += bit[i].order_of_key(mp(y+1, 0));
	return ans;
}

int query(int x1, int x2, int y1, int y2){
	return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
}

int A[200001];
signed main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		insert(i, i);
		A[i] = i;
	}
	int ans = 0;
	for(int i = 0; i < m; i++){
		int l, r;
		cin >> l >> r;
		if(l == r){
			cout << ans << endl;
			continue;
		}
		if(l > r) swap(l, r);
		A[l] < A[r] ? ans++ : ans--;
		int sq = query(l + 1, r - 1, 1, A[l] - 1) + query(l + 1, r - 1, A[r] + 1, n); 
		remove(l, A[l]);
		remove(r, A[r]);
		swap(A[l], A[r]);
		insert(l, A[l]);
		insert(r, A[r]);
		int fq = query(l + 1, r - 1, 1, A[l] - 1) + query(l + 1, r - 1, A[r] + 1, n); 
		ans += fq - sq;
		cout << ans << endl;
	}
}