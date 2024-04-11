#include "bits/stdc++.h"
using namespace std;
const long long inf = 2e18;
struct cht{
	vector < pair < int , int > > hull;
	vector < int > id;
	int cur = 0;
	cht(){
		hull.clear();
		id.clear();
	}
	bool useless(const pair < int , int > left , const pair < int , int > middle , const pair < int , int > right){
		return 1LL * (middle.second - left.second) * (middle.first - right.first) >= 1LL * (right.second - middle.second) * (left.first - middle.first);
	}
	void insert(int idx , int a , int b){
		if(hull.empty()){
			hull.emplace_back(make_pair(a , b));
			id.emplace_back(idx);
		}
		else{
			if(hull.back().first == a){
				if(hull.back().second >= b){
					return;
				}
				else{
					hull.pop_back();
					id.pop_back();
				}
			}
			while(hull.size() >= 2 && useless(hull[hull.size() - 2] , hull.back() , make_pair(a , b))){
				hull.pop_back();
				id.pop_back();
			}
			hull.emplace_back(make_pair(a , b));
			id.emplace_back(idx);
		}
	}
	pair < long long , int > query(int x){
		long long ret = -inf;
		int idx = -1;
		for(int i = cur ; i < hull.size() ; ++i){
			long long tmp = 1LL * hull[i].first * x + hull[i].second;
			if(tmp > ret){
				ret = tmp;
				cur = i;
				idx = id[i];
			}
			else{
				break;
			}
		}
		return {ret , idx};
	}
};
const int N = 1e5 + 5;
const int SN = 1 << 18;
int n , q;
pair < pair < int , int > , int > arr[N];
pair < pair < int , pair < int , int > > , int > que[N];
cht segtree[SN];
int ans[N];
void update(int l , int r , int node , int idx , pair < int , int > line){
	segtree[node].insert(idx , line.first , line.second);
	if(l < r){
		int mid = l + r >> 1;
		if(idx <= mid){
			update(l , mid , node + node , idx , line);
		}
		else{
			update(mid + 1 , r , node + node + 1 , idx , line);
		}
	}
}
pair < long long , int > query(int l , int r , int node , int ql , int qr , int val){
	if(l > qr || r < ql){
		return {-inf , -1};
	}
	if(l >= ql && r <= qr){
		return segtree[node].query(val);
	}
	int mid = l + r >> 1;
	return max(query(l , mid , node + node , ql , qr , val) , query(mid + 1 , r , node + node + 1 , ql , qr , val));
}
int main(){
	scanf("%d %d" , &n , &q);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d" , &arr[i].first.second , &arr[i].first.first);
		arr[i].second = i;
	}
	sort(arr + 1 , arr + 1 + n);
	for(int i = 1 ; i <= n ; ++i){
		update(1 , n , 1 , arr[i].second , arr[i].first);
	}
	for(int i = 1 ; i <= q ; ++i){
		scanf("%d %d %d" , &que[i].first.second.first , &que[i].first.second.second , &que[i].first.first);
		que[i].second = i;
	}
	sort(que + 1 , que + 1 + q);
	for(int i = 1 ; i <= q ; ++i){
		ans[que[i].second] = query(1 , n , 1 , que[i].first.second.first , que[i].first.second.second , que[i].first.first).second;
	}
	for(int i = 1 ; i <= q ; ++i){
		printf("%d\n" , ans[i]);
	}
}