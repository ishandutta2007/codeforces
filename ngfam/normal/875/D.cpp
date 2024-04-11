#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int a[N];

int l[N];
int r[N];
int low[N];
int high[N];
int bit[35];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}


	scanf("%d", &n);

	long long tot = 0;

	for(int i = 1; i <= n; ++i){
		tot += i;

		scanf("%d", a + i);
	
		for(int b = 0; b < 32; ++b){
			if(a[i] & (1 << b)){
				bit[b] = i;
			}
			else{
				low[i] = max(low[i], bit[b] + 1);
			}
		}
	}

	for(int i = 0; i < 32; ++i){
		bit[i] = n + 1;
	}

	for(int i = n; i >= 1; --i){
		high[i] = n;
		for(int b = 0; b < 32; ++b){
			if(a[i] & (1 << b)){
				bit[b] = i;
			}
			else{
				high[i] = min(high[i], bit[b] - 1);
			}
		}	
	}

	stack < int > f;

	for(int i = 1; i <= n; ++i){
		while(!f.empty() && a[f.top()] <= a[i]){
			r[f.top()] = i - 1;
			f.pop();
		}
		if(f.empty()) l[i] = 1;
		else l[i] = f.top() + 1;
		f.push(i);
	}

	while(!f.empty()){
		r[f.top()] = n;
		f.pop();
	}

	for(int i = 1; i <= n; ++i){
		low[i] = max(low[i], l[i]);
		high[i] = min(high[i], r[i]);
		tot -= 1LL * (i - low[i] + 1) * (high[i] - i + 1);
	}

	cout << tot;

	return 0;
}