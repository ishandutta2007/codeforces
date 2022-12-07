#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n;
int x[N];
int a[N];
int mark[N];

priority_queue < int, vector < int >, greater < int > > f;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}


	scanf("%d", &n);


	for(int i = 1; i <= n; ++i){
		int t;
		scanf("%d", &t);


		a[i] = t;

		++x[a[i]];
	}

	for(int i = 1; i <= n; ++i){
		if(x[i] == 0) f.push(i);
	}


	int ans = 0;

	for(int i = 1; i <= n; ++i){
		if(x[a[i]] > 1 && (mark[a[i]] || a[i] > f.top())){
			--x[a[i]];
			a[i] = f.top();
			f.pop();
			++ans;
		}
		else{
			mark[a[i]] = 1;
		}
	}

	printf("%d\n", ans);

	for(int i = 1; i <= n; ++i){
		printf("%d ", a[i]);
	}

	return 0;
}