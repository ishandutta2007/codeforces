#include <bits/stdc++.h>

using namespace std;

#define mid ((l + r) >> 1)

set < pair < int, int > > x;
vector < pair < int, int > > segments;

int calc(int l, int r){
	if(l == r) return 0;
	if(l == r - 1) return 1;

	return 1 + calc(l, mid) + calc(mid, r);
}

int n, k;
int ans[100010];
int current = 0;

void solve(int l, int r, int u, int v, int ok = 0){
	k -= ok;	
	int len = mid - l;


	if(r - l == 1){
		printf("%d ", ans[l] = u);
		return;
	}

	if(k > 0){
		k -= 2;
		solve(l, mid, v - len + 1, v);
		solve(mid, r, u, v - len);
	}
	else{
		solve(l, mid, u, u + len - 1, 0);
		solve(mid, r, u + len, v, 0);
	}

}
	
int cnt = 0;

void check(int l, int r){
	
	if(r - l == 1) return;


	for(int i = l + 1; i < r; ++i){
		if(ans[i] < ans[i - 1]){
			++cnt;
			cout << l << " " << r << endl;
			break;
		} 
	}
	check(l, mid);
	check(mid, r);
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	cin >> n >> k;

	int tot = calc(0, n);


	if(tot < k || k % 2 == 0) cout << -1;
	else{
		solve(0, n, 1, n, 1);
	}


	return 0;
}