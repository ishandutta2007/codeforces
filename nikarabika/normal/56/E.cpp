/*
ID: bug-overflow
LANG: C++11
TASK: 56E
*/

//manam A _____ & an O_o waiting to see U :D

//using sparse table and binary search

#include <bits/stdc++.h>

using namespace std;

#define smax(x, y) ((x) = max((x), (y)))

const int maxn = 1e5 + 85 - 69, maxl = 20;
int x[maxn], xall[maxn], h[maxn], ans[maxn], dp_sparse_table[maxn][maxl], ele[maxn];
int n;

int get(int st, int en){
	if(en <= st)
		return st - 1;
	int ret = 0;
	for(int i = 0; i < maxl; i++)
		if(((en - st) >> i) & 1){
			smax(ret, dp_sparse_table[st][i]);
			st += (1 << i);;
		}
	return ret;
}

void modify(int idx, int val){
	dp_sparse_table[idx][0] = val;
	for(int i = 1; i < maxl and idx + (1 << i) <= maxn; i++)
		dp_sparse_table[idx][i] = max(dp_sparse_table[idx][i - 1],
				dp_sparse_table[idx + (1 << (i - 1))][i - 1]);
	return;
}

bool eleCmp(int a, int b){
	return x[a] < x[b];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> h[i];
		xall[i] = x[i];
		ele[i] = i;
	}
	sort(ele, ele + n, eleCmp);
	sort(xall, xall + n);
	for(int i = n - 1; i >= 0; i--){
		int idx = ele[i];
		int id = lower_bound(xall, xall + n, x[idx] + h[idx]) - xall;
		modify(i, get(i + 1, id));
	}
	for(int i = 0; i < n; i++)
		ans[ele[i]] = dp_sparse_table[i][0] - i + 1;
	for(int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}