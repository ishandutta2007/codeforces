#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int LN = 45;
int n;
long long arr[N];
map < long long , int > mp;
int cnt[LN];
vector < long long > v;
bool check(int chains){
	int cur = chains;
	int tot = 0;
	int ptr = 0;
	for(int i = 0 ; i < LN ; ++i){
		if(cnt[i] > cur){
			tot += cnt[i] - cur;
		}
		if(cnt[i] < cur){
			int lft = cur - cnt[i];
			int idx = lower_bound(v.begin() , v.end() , (1LL << i) + 1) - v.begin();
			--idx;
			idx = min(idx , ptr + lft - 1);
			lft -= max(ptr , idx + 1) - ptr;
			ptr = max(ptr , idx + 1);
			if(lft > 0){
				tot -= lft;
				tot = max(0 , tot);
			}
			cur = cnt[i];
		}
	}
	return tot + (v.size() - ptr) <= cur;
}
int main(){
	mp.clear();
	for(int i = 0 ; i < LN ; ++i){
		mp[1LL << i] = i;
	}
	scanf("%d" , &n);
	int ones = 0;
	int leafs = 0;
	memset(cnt , 0 , sizeof(cnt));
	v.clear();
	for(int i = 1 ; i <= n ; ++i){
		scanf("%lld" , arr + i);
		if(arr[i] == 1){
			++ones;
		}
		if(mp.find(arr[i]) == mp.end()){
			++leafs;
			v.emplace_back(arr[i]);
		}
		else{
			++cnt[mp[arr[i]]];
		}
	}
	vector < int > ans;
	ans.clear();
	leafs = max(leafs , 1);
	for(int i = leafs ; i <= ones ; ++i){
		if(check(i)){
			ans.emplace_back(i);
		}
	}
	if(ans.empty()){
		printf("-1\n");
	}
	else{
		for(int x : ans){
			printf("%d " , x);
		}
		printf("\n");
	}
}