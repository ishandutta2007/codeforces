#include <bits/stdc++.h>

using namespace std;

const int N = 345678;

int v[N], n, add[N];

typedef pair<int,int> ii;

ii a[N];

set < int > done;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i].first);
		a[i].second = i;
	}

	sort(a + 1, a + n + 1);

	for(int i = 1; i <= n; ++i){
		//cout << a[i].second << " ";
		if(done.count(a[i].first)) a[i].first = a[i - 1].first + 1;
		done.insert(a[i].first);		
	}

	for(int i = 1; i <= n; ++i){
		v[a[i].second] = a[i].first;
	}

	for(int i = 1; i <= n; ++i){
		printf("%d ", v[i]);
	}
}