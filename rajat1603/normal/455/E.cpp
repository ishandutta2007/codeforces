#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int inf = 2e9;
int n;
int arr[N];
int sum[N];
int q;
struct cht{
	vector < pair < int , int > > hull;
	int cur = 0;
	cht(){
		hull.clear();
	}
	inline bool useless(const pair < int , int > &left , const pair < int , int > &middle , const pair < int , int > right){
		return 1LL * (middle.second - left.second) * (middle.first - right.first) >= 1LL * (right.second - middle.second) * (left.first - middle.first);
	}
	inline void insert(int a , int b){
		if(hull.empty()){
			hull.emplace_back(make_pair(a , b));
		}
		else{
			if(hull.back().first == a){
				if(hull.back().second <= b){
					return;
				}
				else{
					hull.pop_back();
				}
			}
			while(hull.size() >= 2 && useless(hull[hull.size() - 2] , hull.back() , make_pair(a , b))){
				hull.pop_back();
			}
			hull.emplace_back(make_pair(a , b));
		}
	}
	inline int query(int x){
		if(hull.empty()){
			return inf;
		}
		while(((cur + 1) < hull.size()) && (hull[cur + 1].second - hull[cur].second <= 1LL * x * (hull[cur].first - hull[cur + 1].first))){
			++cur;
		}
		return hull[cur].first * x + hull[cur].second;
	}
};
const int SN = 1 << 18;
cht segtree[SN];
int ans[N];
int a[N];
int b[N];
vector < pair < int , int > > v;
void update(int l , int r , int node , int idx , int a , int b){
	segtree[node].insert(a , b);
	if(l < r){
		int mid = l + r >> 1;
		if(idx <= mid){
			update(l , mid , node + node , idx , a , b);
		}
		else{
			update(mid + 1 , r , node + node + 1 , idx , a , b);
		}
	}
}
int query(int l , int r , int node , int ql , int qr , int x){
	if(l > qr || r < ql){
		return inf;
	}
	if(l >= ql && r <= qr){
		return segtree[node].query(x);
	}
	int mid = l + r >> 1;
	return min(query(l , mid , node + node , ql , qr , x) , query(mid + 1 , r , node + node + 1 , ql , qr , x));
}
int main(){
	scanf("%d" , &n);
	v.clear();
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		sum[i] = sum[i - 1] + arr[i];
		v.emplace_back(make_pair(arr[i] , i));
	}
	sort(v.begin() , v.end());
	reverse(v.begin() , v.end());
	for(auto it : v){
		update(1 , n , 1 , it.second , it.first , it.first * it.second - sum[it.second]);
	}
	v.clear();
	scanf("%d" , &q);
	for(int i = 1 ; i <= q ; ++i){
		scanf("%d %d" , a + i , b + i);
		v.emplace_back(make_pair(a[i] - b[i] , i));
	}
	sort(v.begin() , v.end());
	for(auto it : v){ 
		ans[it.second] = query(1 , n , 1 , b[it.second] - a[it.second] + 1 , b[it.second] , it.first) + sum[b[it.second]];
	}
	for(int i = 1 ; i <= q ; ++i){
		printf("%d\n" , ans[i]);
	}
}