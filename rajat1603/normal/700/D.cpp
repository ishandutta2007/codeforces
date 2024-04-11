#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SN = 1 << 18;
const int SQN = 330;
int n;
int arr[N];
int q;
struct data{
	int l , r , idx;
	bool operator < (const data &o) const {
		if(int(l / SQN) == int(o.l / SQN)){
			return r < o.r;
		}
		return l < o.l;
	}
};
data que[N];
int ans[N];
int freq1[N];
int segtree[SN];
int leaf[N];
void build(int l , int r , int node){
	segtree[node] = 0;
	if(l == r){
		leaf[l] = node;
	}
	else{
		int mid = l + r >> 1;
		build(l , mid , node + node);
		build(mid + 1 , r , node + node + 1);
	}
}
inline void segtreeupdate(int idx , int add){
	int node = leaf[idx];
	segtree[node] += add;
	node >>= 1;
	while(node){
		segtree[node] = segtree[node + node] | segtree[node + node + 1];
		node >>= 1;
	}
}
inline void update(int idx , int add){
	int val = arr[idx];
	if(freq1[val]){
		segtreeupdate(freq1[val] , -1);
	}
	freq1[val] += add;
	if(freq1[val]){
		segtreeupdate(freq1[val] , 1);
	}
}
int cnt[N];
void query(int l , int r , int node , priority_queue < int > &pq){
	if(!segtree[node]){
		return;
	}
	if(l == r){
		pq.push(-l);
		cnt[l] = segtree[node];
		return;
	}
	int mid = l + r >> 1;
	query(l , mid , node + node , pq);
	query(mid + 1 , r , node + node + 1 , pq);
}
inline int solve(){
	priority_queue < int > pq;
	while(!pq.empty()){
		pq.pop();
	}
	query(1 , n , 1 , pq);
	int ans = 0;
	while(!pq.empty()){
		int val = -pq.top();
		int fre = cnt[val];
		cnt[val] = 0;
		pq.pop();
		if(fre > 1){
			if(!cnt[val << 1]){
				pq.push(-(val << 1));
			}
			cnt[val << 1] += fre >> 1;
			ans += val * ((fre >> 1) << 1);
			fre &= 1;
		}
		if(fre){
			if(pq.empty()){
				break;
			}
			int val2 = -pq.top();
			--cnt[val2];
			if(!cnt[val2]){
				pq.pop();
			}
			ans += val + val2;
			++cnt[val + val2];
			if(cnt[val + val2] == 1){
				pq.push(-(val + val2));
			}
		}
	}
	return ans;
}
int main(){
	scanf("%d" , &n);
	build(1 , n , 1);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	scanf("%d" , &q);
	for(int i = 1 ; i <= q ; ++i){
		scanf("%d %d" , &que[i].l , &que[i].r);
		que[i].idx = i;
	}
	sort(que + 1 , que + 1 + q);
	int curl = 1;
	int curr = 0;
	for(int i = 1 ; i <= q ; ++i){
		while(curr < que[i].r){
			update(++curr , 1);
		}
		while(curl > que[i].l){
			update(--curl , 1);
		}
		while(curr > que[i].r){
			update(curr-- , -1);
		}
		while(curl < que[i].l){
			update(curl++ , -1);
		}
		ans[que[i].idx] = solve();
	}
	for(int i = 1 ; i <= q ; ++i){
		printf("%d\n" , ans[i]);
	}
}