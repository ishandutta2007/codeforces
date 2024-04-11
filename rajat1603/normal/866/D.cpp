#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
const int SN = 1 << 20;
const int inf = 1e9 + 9;
struct data{
	int mini;
	int idx;
	int pref;
	int sum;
};
inline data combine(const data &lft , const data &rgt){
	data res;
	res.sum = lft.sum + rgt.sum;
	res.mini = min(lft.mini , rgt.mini);
	if(lft.mini == res.mini){
		res.idx = lft.idx;
	}
	else{
		res.idx = rgt.idx;
	}
	res.pref = min(lft.pref , rgt.pref + lft.sum);
	return res;
}
int n;
int arr[N];
data segtree[SN];
int done[N];
pair < int , int > inp[N];
void build(int l , int r , int node){
	if(l == r){
		segtree[node].mini = arr[l];
		segtree[node].idx = r;
		segtree[node].pref = 0;
		segtree[node].sum = 0;
	}
	else{
		int mid = l + r >> 1;
		build(l , mid , node + node);
		build(mid + 1 , r , node + node + 1);
		segtree[node] = combine(segtree[node + node] , segtree[node + node + 1]);
	}
}
void update(int l , int r , int node , int idx , int val){
	if(l == r){
		segtree[node].mini = inf;
		segtree[node].idx = inf;
		segtree[node].pref = val;
		segtree[node].sum = val;
	}
	else{
		int mid = l + r >> 1;
		if(idx <= mid){
			update(l , mid , node + node , idx , val);
		}
		else{
			update(mid + 1 , r , node + node + 1 , idx , val);
		}
		segtree[node] = combine(segtree[node + node] , segtree[node + node + 1]);
	}
}
int get(){
	int l = 1;
	int r = n;
	int node = 1;
	int sum = 0;
	while(l < r){
		int mid = l + r >> 1;
		if(sum + segtree[node + node].pref < 0){
			r = mid;
			node = node + node;
		}
		else{
			sum += segtree[node + node].sum;
			l = mid + 1;
			node = node + node + 1;
		}
	}
	return l;
}
pair < int , int > query(int l , int r , int node , int ql , int qr){
	if(l > qr || r < ql){
		return {inf , inf};
	}
	if(l >= ql && r <= qr){
		return {segtree[node].mini , segtree[node].idx};
	}
	int mid = l + r >> 1;
	return min(query(l , mid , node + node , ql , qr) , query(mid + 1 , r , node + node + 1 , ql , qr));
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		inp[i].first = arr[i];
		inp[i].second = i;
	}
	build(1 , n , 1);
	sort(inp + 1 , inp + 1 + n);
	reverse(inp + 1 , inp + 1 + n);
	long long ans = 0;
	for(int i = 1 ; i <= n ; ++i){
		int idx = inp[i].second;
		if(done[idx]){
			continue;
		}
		update(1 , n , 1 , idx , -1);
		int lft = get();
		auto tmp = query(1 , n , 1 , 1 , lft);
		if(tmp.first == inf){
			update(1 , n , 1 , idx , 0);
		}
		else{
			ans += arr[idx] - tmp.first;
			done[tmp.second] = 1;
			update(1 , n , 1 , tmp.second , 1);
		}
		done[idx] = 1;
	}
	printf("%lld\n" , ans);
}