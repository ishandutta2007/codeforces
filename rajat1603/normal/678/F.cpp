#include "bits/stdc++.h"
using namespace std;
const long long inf = 2e18;
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
				if(hull.back().second >= b){
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
	inline long long query(int x){
		if(hull.empty()){
			return -inf;
		}
		while(((cur + 1) < hull.size()) && (hull[cur + 1].second - hull[cur].second >= 1LL * x * (hull[cur].first - hull[cur + 1].first))){
			++cur;
		}
		return 1LL * hull[cur].first * x + hull[cur].second;
	}
};
const int N = 3e5 + 5;
const int SN = 1 << 20;
int n;
int type[N];
int a[N];
int b[N];
int x[N];
cht segtree[SN];
void update(int l , int r , int node , int ql , int qr , int a , int b){
	if(l > qr || r < ql){
		return;
	}
	if(l >= ql && r <= qr){
		segtree[node].insert(a , b);
		return;
	}
	int mid = l + r >> 1;
	update(l , mid , node + node , ql , qr , a , b);
	update(mid + 1 , r , node + node + 1 , ql , qr , a , b);
}
long long query(int l , int r , int node , int idx , int val){
	long long ret = segtree[node].query(val);
	if(l < r){
		int mid = l + r >> 1;
		if(idx <= mid){
			ret = max(ret , query(l , mid , node + node , idx , val));
		}
		else{
			ret = max(ret , query(mid + 1 , r , node + node + 1 , idx , val));
		}
	}
	return ret;
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &type[i]);
		if(type[i] == 1){
			scanf("%d %d" , &a[i] , &b[i]);
			x[i] = n;
		}
		else if(type[i] == 2){
			scanf("%d" , &x[i]);
			x[x[i]] = i - 1;
		}
		else{
			scanf("%d" , &x[i]);
		}
	}
	vector < pair < int , int > > vv;
	vv.clear();
	for(int i = 1 ; i <= n ; ++i){
		if(type[i] == 1){
			vv.emplace_back(make_pair(a[i] , i));
		}
	}
	sort(vv.begin() , vv.end());
	for(auto it : vv){
		update(1 , n , 1 , it.second , x[it.second] , it.first , b[it.second]);
	}
	vv.clear();
	for(int i = 1 ; i <= n ; ++i){
		if(type[i] == 3){
			vv.emplace_back(make_pair(x[i] , i));
		}
	}
	sort(vv.begin() , vv.end());
	vector < pair < int , long long > > ans;
	ans.clear();
	for(auto it : vv){
		ans.emplace_back(make_pair(it.second , query(1 , n , 1 , it.second , it.first)));
	}
	sort(ans.begin() , ans.end());
	for(auto it : ans){
		if(it.second <= -inf){
			printf("EMPTY SET\n");
		}
		else{
			printf("%lld\n" , it.second);
		}
	}
}