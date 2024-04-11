#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
pair < pair < int , int > , int > arr[N];
int s[N];
int sz;
vector < int > ans;
set < pair < int , int > > ss;
bool useless(pair < int , int > lft , pair < int , int > mid , pair < int , int > rgt){
	return 1LL * (lft.second - mid.second) * (rgt.first - mid.first) * rgt.second * lft.first > 1LL * (mid.second - rgt.second) * (mid.first - lft.first) * lft.second * rgt.first;
}
bool lol(pair < int , int > lft , pair < int , int > rgt){
	long long num = 1LL * (lft.second - rgt.second) * lft.first * rgt.first;
	long long den = 1LL * (rgt.first - lft.first) * lft.second * rgt.second;
	return !num || ((num / llabs(num)) != (den / llabs(den)));
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d" , &arr[i].first.first , &arr[i].first.second);
		arr[i].second = i;
	}
	sort(arr + 1 , arr + 1 + n);
	sz = 0;
	for(int i = 1 ; i <= n ; ++i){
		while(sz >= 1 && arr[s[sz]].first.first == arr[i].first.first && arr[s[sz]].first.second <= arr[i].first.second){
			--sz;
		}
		while(sz >= 2 && useless(arr[s[sz - 1]].first , arr[s[sz]].first , arr[i].first)){
			--sz;
		}
		s[++sz] = i;
	}
	for(int i = 1 ; i <= sz ; ++i){
		if(i < sz){
			if(lol(arr[s[i]].first , arr[s[i + 1]].first)){
				continue;
			}
		}
		ss.insert(arr[s[i]].first);
	}
	for(int i = 1 ; i <= n ; ++i){
		if(ss.find(arr[i].first) != ss.end()){
			ans.emplace_back(arr[i].second);
		}
	}
	sort(ans.begin() , ans.end());
	for(int x : ans){
		printf("%d " , x);
	}
}