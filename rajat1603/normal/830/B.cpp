#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
//const int SN = 1 << 18;
const int inf = 1e6 + 6;
int n;
pair < int , int > arr[N];
vector < int > v;
//pair < int , int > segtree[SN];
int bit[N];
int ptr;
long long ans;
void update(int idx , int val){
	while(idx <= n){
		bit[idx] += val;
		idx += idx & -idx;
	}
}
int query(int idx){
	int res = 0;
	while(idx){
		res += bit[idx];
		idx -= idx & -idx;
	}
	return res;
}
int query(int l , int r){
	if(l <= r){
		return query(r) - query(l - 1);
	}
	return 0;
}
/*void build(int l , int r , int node){
	if(l == r){
		segtree[node] = make_pair(arr[l] , r);
	}
	else{
		int mid = l + r >> 1;
		build(l , mid , node + node);
		build(mid + 1 , r , node + node + 1);
		segtree[node] = min(segtree[node + node] , segtree[node + node + 1]);
	}
}
void update(int l , int r , int node , int idx){
	if(l == r){
		segtree[node] = make_pair(inf , inf);
	}
	else{
		int mid = l + r >> 1;
		if(idx <= mid){
			update(l , mid , node + node , idx);
		}
		else{
			update(mid + 1 , r , node + node + 1 , idx);
		}
		segtree[node] = min(segtree[node + node] , segtree[node + node + 1]);
	}
}
pair < int , int > query(int l , int r , int node , int ql , int qr){
	if(l > qr || r < ql || ql > qr){
		return make_pair(inf , inf);
	}
	if(l >= ql && r <= qr){
		return segtree[node];
	}
	int mid = l + r >> 1;
	return min(query(l , mid , node + node , ql , qr) , query(mid + 1 , r , node + node + 1 , ql , qr));
}*/
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &arr[i].first);
		arr[i].second = i;
	}
	for(int i = 1 ; i <= n ; ++i){
		update(i , 1);
	}
	//build(1 , n , 1);
	ans = 0;
	ptr = 0;
	sort(arr + 1 , arr + 1 + n);
	for(int i = 1 ; i <= n ; ++i){
		int j = i;
		while(j + 1 <= n && arr[j + 1].first == arr[i].first){
			++j;
		}
		for(int k = i ; k <= j ; ++k){
			if(arr[k].second > ptr){
				v.emplace_back(arr[k].second);
			}
		}
		for(int k = i ; k <= j ; ++k){
			if(arr[k].second < ptr){
				v.emplace_back(arr[k].second);
			}
		}
		ptr = v.back();
		i = j;
	}
	ptr = 1;
	for(int x : v){
		if(x >= ptr){
			ans += query(ptr , x);
		}
		else{
			ans += query(ptr , n);
			ans += query(1 , x);
		}
		ptr = x;
		update(ptr , -1);
	}
	printf("%lld\n" , ans);
}