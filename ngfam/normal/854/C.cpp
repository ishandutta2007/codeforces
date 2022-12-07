#include <bits/stdc++.h>

using namespace std;

const int N = 500050;

int n, k;
int lst[N];
pair < long long, long long > a[N];

bool cmp(pair < long long, long long > u, pair < long long, long long > v){
	return u.second < v.second;	
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d%d", &n, &k);

	for(int i = 1; i <= n; ++i){
		a[i].second = i;
		scanf("%lld", &a[i].first);
	}

	int days = k + 1;

	int pter = 1;


	priority_queue < pair < long long, long long > > heap;

	sort(a + 1, a + n + 1, cmp);

	/*for(int i = 1; i <= n; ++i){
		cout << a[i].first << " " << a[i].second << endl;
	}*/


	long long ans = 0;


	for(int i = 1; i <= n; ++i){
		while(pter <= n && a[pter].second <= days){
			heap.push(a[pter]);
			++pter;
		}
		//cout << i << " " << pter << endl;
		ans += heap.top().first * (days - heap.top().second);
		lst[heap.top().second] = days;
		heap.pop();
		++days;

	}

	printf("%lld\n", ans);

	for(int i = 0; i < n; ++i){
		printf("%d ", lst[i + 1]);
	}

	return 0;
}