#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 5;
int n;
int l[N] , r[N];
vector < int > v;
int tot[N];
int lst[N];
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d" , l + i , r + i);
		v.emplace_back(l[i]);
		v.emplace_back(r[i] + 1);
		v.emplace_back(r[i]);
		v.emplace_back(l[i] - 1);
	}
	sort(v.begin() , v.end());
	v.resize(unique(v.begin() , v.end()) - v.begin());
	for(int i = 1 ; i <= n ; ++i){
		l[i] = lower_bound(v.begin() , v.end() , l[i]) - v.begin() + 1;
		r[i] = lower_bound(v.begin() , v.end() , r[i]) - v.begin() + 1;
		++tot[l[i]];
		--tot[r[i] + 1];
	}
	for(int i = 1 ; i < N ; ++i){
		tot[i] += tot[i - 1];
	}
	lst[0] = 0;
	for(int i = 1 ; i < N ; ++i){
		if(tot[i] >= 2){
			lst[i] = lst[i - 1];
		}
		else{
			lst[i] = i;
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		if(lst[r[i]] < l[i]){
			printf("%d\n" , i);
			return 0;
		}
	}
	printf("-1\n");
}