#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n , a;
int arr[N];
vector < int > v[N];
int cnt[N];
int main(){
	scanf("%d %d" , &n , &a);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		cnt[i] = cnt[i - 1] + (arr[i] == a);
		v[arr[i]].emplace_back(i);
	}
	for(int i = 1 ; i < N ; ++i){
		if(i == a){
			continue;
		}
		bool ok = 1;
		int tot = 0;
		for(int idx : v[i]){
			if(tot < cnt[idx - 1]){
				ok = 0;
			}
			++tot;
		}
		if(tot < cnt[n]){
			ok = 0;
		}
		if(ok){
			printf("%d\n" , i);
			return 0;
		}
	}
	printf("-1\n");
}