#include "bits/stdc++.h"
using namespace std;
const int N = 5e4 + 4;
const int K = 12;
int n , k;
int arr[N][K];
struct scc{
	int mini[K];
	int maxi[K];
	int siz;
	bool operator < (const scc &other) const {
		for(int i = 1 ; i <= k ; ++i){
			if(maxi[i] >= other.mini[i]){
				return 0;
			}
		}
		return 1;
	}
	bool operator == (const scc &other) const {
		for(int i = 1 ; i <= k ; ++i){
			if(mini[i] != other.mini[i]){
				return 0;
			}
			if(maxi[i] != other.maxi[i]){
				return 0;
			}
		}
		return 1;
	}
};
scc all[N * 3];
int cur;
set < scc > groups;
set < pair < int , int > > lft[K];
set < pair < int , int > > rgt[K];

void insert(scc me){
	if(groups.empty() || *prev(groups.end()) < me || me < *groups.begin()){
		++cur;
		all[cur] = me;
		groups.insert(me);
		for(int i = 1 ; i <= k ; ++i){
			lft[i].insert(make_pair(me.mini[i] , cur));
			rgt[i].insert(make_pair(me.maxi[i] , cur));
		}
		return;
	}
	scc start = *groups.begin();
	scc finish = *prev(groups.end());
	for(int i = 1 ; i <= k ; ++i){
		auto it = lft[i].lower_bound(make_pair(me.maxi[i] + 1 , -1));
		if(it != lft[i].begin()){
			--it;
			if(!(me < all[it -> second])){
				start = max(start , all[it -> second]);
			}
		}
	}
	for(int i = 1 ; i <= k ; ++i){
		auto it = rgt[i].lower_bound(make_pair(me.mini[i] , -1));
		if(it != rgt[i].end()){
			if(!(all[it -> second] < me)){
				finish = min(finish , all[it -> second]);
			}
		}
	}
	if(start == finish || finish < start){
		auto it = groups.lower_bound(finish);
		scc val;
		do{
			for(int j = 1 ; j <= k ; ++j){
				me.mini[j] = min(me.mini[j] , it -> mini[j]);
				me.maxi[j] = max(me.maxi[j] , it -> maxi[j]);
			}
			me.siz += it -> siz;
			val = *it;
			groups.erase(it);
			for(int i = 1 ; i <= k ; ++i){
				auto del1 = lft[i].lower_bound(make_pair(val.mini[i] , -1));
				lft[i].erase(del1);
				auto del2 = rgt[i].lower_bound(make_pair(val.maxi[i] , -1));
				rgt[i].erase(del2);
			}
			it = groups.lower_bound(finish);
		}
		while(!(val == start));
	}
	++cur;
	all[cur] = me;
	groups.insert(me);
	for(int i = 1 ; i <= k ; ++i){
		lft[i].insert(make_pair(me.mini[i] , cur));
		rgt[i].insert(make_pair(me.maxi[i] , cur));
	}
}
int main(){
	scanf("%d %d" , &n , &k);
	cur = 0;
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= k ; ++j){
			scanf("%d" , &arr[i][j]);
		}
		scc me;
		for(int j = 1 ; j <= k ; ++j){
			me.mini[j] = arr[i][j];
			me.maxi[j] = arr[i][j];
		}
		me.siz = 1;
		insert(me);
		printf("%d\n" , prev(groups.end()) -> siz);
	}
}