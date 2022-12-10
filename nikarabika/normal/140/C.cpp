#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int T[maxn * 4];
int n;
int a[maxn];
int ans[maxn / 3];

int get(int l, int r, int L = 0, int R = n, int id = 1){
	if(l == L and r == R)
		return T[id];
	int mid = (L + R) >> 1;
	int sum = 0;
	if(r > mid)
		sum += get(max(l, mid), r, mid, R, id * 2 + 1);
	if(l < mid)
		sum += get(l, min(mid, r), L, mid, id * 2 + 0);
	return sum;
}

void add(int idx, int L = 0, int R = n, int id = 1){
	T[id]++;
	if(R - L == 1)
		return;
	int mid = (L + R) >> 1;
	if(idx < mid)
		add(idx, L, mid, id * 2 + 0);
	else
		add(idx, mid, R, id * 2 + 1);
}

int findin(int l, int r){
	while(r - l > 1){
		int mid = (l + r) >> 1;
		if(get(l, mid) < mid - l)
			r = mid;
		else
			l = mid;
	}
	if(get(l, r) == 1)
		return -1;
	return l;
}

bool can(int k){
	for(int i = 0; i < k; i++){
		int l = max(upper_bound(a, a + n, a[i]) - a, int(k)),
			r = min(lower_bound(a, a + n, a[n - k + i]) - a, int(n - k));
		if(l >= r)
			return false;
		int id = findin(l, r);
		if(id == -1)
			return false;
		add(id);
		ans[i] = id;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int lo = 0, hi = n / 3 + 1;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(can(mid))
			lo = mid;
		else
			hi = mid;
		memset(T, 0, sizeof T);
	}
	cout << lo << endl;
	if(lo == 0)
		return 0;
	can(lo);
	for(int i = 0; i < lo; i++){
		cout << a[n - lo + i] << ' ' << a[ans[i]] << ' ' << a[i] << endl;
	}
	return 0;
}