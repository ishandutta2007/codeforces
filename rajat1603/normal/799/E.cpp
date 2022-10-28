#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int SN = 1 << 19;
const long long inf = 1e15 + 15;
int n , m , k;
int c[N];
int a;
bool likea[N];
int b;
bool likeb[N];
vector < pair < long long , int > > no;
vector < pair < long long , int > > aa;
vector < pair < long long , int > > bb;
vector < pair < long long , int > > ab;
long long sum[SN];
int cnt[SN];
void build(int l , int r , int node){
	if(l == r){
		sum[node] = c[l];
		cnt[node] = 1;
	}
	else{
		int mid = l + r >> 1;
		build(l , mid , node + node);
		build(mid + 1 , r , node + node + 1);
		sum[node] = sum[node + node] + sum[node + node + 1];
		cnt[node] = cnt[node + node] + cnt[node + node + 1];
	}
}
void update(int l , int r , int node , int idx , int val){
	cnt[node] += val;
	sum[node] += c[idx] * val;
	if(l < r){
		int mid = l + r >> 1;
		if(idx <= mid){
			update(l , mid , node + node , idx , val);
		}
		else{
			update(mid + 1 , r , node + node + 1 , idx , val);
		}
	}
}
pair < long long , int > query(int l , int r , int node , int k){
	if(k <= 0){
		return make_pair(0 , 0);
	}
	if(cnt[node] < k){
		return make_pair(sum[node] , cnt[node]);
	}
	if(l == r){
		return make_pair(sum[node] , cnt[node]);
	}
	int mid = l + r >> 1;
	auto res = query(l , mid , node + node , k);
	if(res.second < k){
		auto tmp = query(mid + 1 , r , node + node + 1 , k - res.second);
		res.first += tmp.first;
		res.second += tmp.second;
	}
	return res;
}
int aptr , bptr;
long long solve(int done){
	int left = k - done;
	if(aa.size() < left || bb.size() < left){
		return inf;
	}
	while(aptr > left){
		update(1 , n , 1 , aa[aptr - 1].second , 1);
		--aptr;
	}
	while(bptr > left){
		update(1 , n , 1 , bb[bptr - 1].second , 1);
		--bptr;
	}
	long long res = 0;
	if(left){
		res += aa[left - 1].first;
		res += bb[left - 1].first;
	}
	int tot = done + left * 2;
	if(tot > m){
		return inf;
	}
	auto it = query(1 , n , 1 , m - tot);
	if(it.second < m - tot){
		return inf;
	}
	//cout << res << " " << it.first << " " << it.second << endl;
	res += it.first;
	return res;
}
pair < int , int > inp[N];
int idx[N];
int main(){
	scanf("%d %d %d" , &n , &m , &k);
	if(k > m){
		printf("-1\n");
		return 0;
	}
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &inp[i].first);
		inp[i].second = i;
	}
	sort(inp + 1 , inp + 1 + n);
	for(int i = 1 ; i <= n ; ++i){
		c[i] = inp[i].first;
		idx[inp[i].second] = i;
	}
	scanf("%d" , &a);
	for(int i = 1 ; i <= a ; ++i){
		int inp;
		scanf("%d" , &inp);
		likea[idx[inp]] = 1;
	}
	scanf("%d" , &b);
	for(int i = 1 ; i <= b ; ++i){
		int inp;
		scanf("%d" , &inp);
		likeb[idx[inp]] = 1;
	}
	for(int i = 1 ; i <= n ; ++i){
		if(likea[i] && likeb[i]){
			long long add = 0;
			if(!ab.empty()){
				add += ab.back().first;
			}
			ab.push_back({c[i] + add , i});
		}
		else if(likea[i]){
			long long add = 0;
			if(!aa.empty()){
				add += aa.back().first;
			}
			aa.push_back({c[i] + add , i});
		}
		else if(likeb[i]){
			long long add = 0;
			if(!bb.empty()){
				add += bb.back().first;
			}
			bb.push_back({c[i] + add , i});
		}
		else{
			long long add = 0;
			if(!no.empty()){
				add += no.back().first;
			}
			no.push_back({c[i] + add , i});
		}
	}
	build(1 , n , 1);
	for(auto it : aa){
		update(1 , n , 1 , it.second , -1);
	}
	for(auto it : bb){
		update(1 , n , 1 , it.second , -1);
	}
	aptr = aa.size();
	bptr = bb.size();
	long long ans = inf;
	ans = min(ans , solve(0));
	for(int i = 1 ; i <= k && i <= ab.size() ; ++i){
		update(1 , n , 1 , ab[i - 1].second , -1);
		ans = min(ans , solve(i) + ab[i - 1].first);
	}
	if(ans >= inf){
		ans = -1;
	}
	printf("%lld\n" , ans);
}