#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int SQN = 330;
int n , k;
int type[N];
int arr[N];
int q;
pair < pair < int , int > , int > que[N];
long long ans[N];

long long pre[N];
int who[N];
int lft[N];
int rgt[N];
vector < long long > v;

int rcnt[N];
int lcnt[N];
long long curans;
int curl , curr;

inline void insertright(int idx){
	++lcnt[who[idx - 1]];
	if(rgt[idx] != -1){
		curans += lcnt[rgt[idx]];
	}
	++rcnt[who[idx]];
}
inline void deleteright(int idx){
	--rcnt[who[idx]];
	if(rgt[idx] != -1){
		curans -= lcnt[rgt[idx]];
	}
	--lcnt[who[idx - 1]];
}
inline void insertleft(int idx){
	++rcnt[who[idx]];
	if(lft[idx] != -1){
		curans += rcnt[lft[idx]];
	}
	++lcnt[who[idx - 1]];
}
inline void deleteleft(int idx){
	--lcnt[who[idx - 1]];
	if(lft[idx] != -1){
		curans -= rcnt[lft[idx]];
	}
	--rcnt[who[idx]];
}
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , type + i);
	}
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		if(type[i] == 2){
			arr[i] *= -1;
		}
	}
	pre[0] = 0;
	for(int i = 1 ; i <= n ; ++i){
		pre[i] = pre[i - 1] + arr[i];
	}
	v.clear();
	for(int i = 0 ; i <= n ; ++i){
		v.emplace_back(pre[i]);
	}
	sort(v.begin() , v.end());
	v.resize(unique(v.begin() , v.end()) - v.begin());
	for(int i = 0 ; i <= n ; ++i){
		who[i] = lower_bound(v.begin() , v.end() , pre[i]) - v.begin() + 1;
	}
	for(int i = 1 ; i <= n ; ++i){
		auto it = lower_bound(v.begin() , v.end() , pre[i] - k);
		if(it != v.end() && *it == pre[i] - k){
			rgt[i] = it - v.begin() + 1;
		}
		else{
			rgt[i] = -1;
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		auto it = lower_bound(v.begin() , v.end() , pre[i - 1] + k);
		if(it != v.end() && *it == pre[i - 1] + k){
			lft[i] = it - v.begin() + 1;
		}
		else{
			lft[i] = -1;
		}
	}
	scanf("%d" , &q);
	for(int i = 1 ; i <= q ; ++i){
		scanf("%d %d" , &que[i].first.first , &que[i].first.second);
		que[i].second = i;
	}
	sort(que + 1 , que + 1 + q , [](pair < pair < int , int > , int > a , pair < pair < int , int > , int > b){
		if(int(a.first.first / SQN) == int(b.first.first / SQN)){
			return a.first.second < b.first.second;
		}
		return a.first.first < b.first.first;
	});
	curl = 1;
	curr = 0;
	curans = 0;
	for(int i = 1 ; i <= q ; ++i){
		int l = que[i].first.first;
		int r = que[i].first.second;
		int idx = que[i].second;
		while(curr < r){
			insertright(++curr);
		}
		while(curl > l){
			insertleft(--curl);
		}
		while(curr > r){
			deleteright(curr--);
		}
		while(curl < l){
			deleteleft(curl++);
		}
		ans[idx] = curans;
	}
	for(int i = 1 ; i <= q ; ++i){
		printf("%lld\n" , ans[i]);
	}
}