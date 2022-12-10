#include <bits/stdc++.h>

using namespace std;

#define L first
#define R second

const int maxn = 2e5 + 100;
int fen[maxn * 2];
pair<int, int> a[maxn];
int n, ans[maxn];

void add(int idx){
	idx++;
	while(idx < maxn){
		fen[idx]++;
		idx += idx & (-idx);
	}
}

int get(int e){
	e++;
	int sum = 0;
	while(e > 0){
		sum += fen[e];
		e -= e & (-e);
	}
	return sum;
}

int get(int b, int e){
	return get(e) - get(b - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i].L, a[i].R = i;
	sort(a, a + n);
	for(int i = 0; i < n; i++){
		int idx = a[i].R;
		for(int k = 1; k < n and k * idx + 1 < n; k++)
			ans[k] += get(k * idx + 1, min(k * (idx + 1), n + 10));
		add(idx);
	}
	for(int i = 1; i < n; i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}