#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
int n;
int arr[N];
long long ans;
struct data{
	int mx;
	int mn;
	int id;
	char type;
	data(){

	}
	data(int Max , int Min , int idx , char typ){
		mx = Max;
		mn = Min;
		id = idx;
		type = typ;
	}
	bool operator < (const data &other) const {
		return mx < other.mx;
	}
};
data tmp[N];
int siz;
vector < int > vl[N];
vector < int > vr[N];
vector < int > vlminl[N << 1];
vector < int > vrminr[N << 1];
int markl[N];
int markr[N];
int marklminl[N << 1];
int markminr[N << 1];
vector < int > bitl[N];
vector < int > bitr[N];
vector < int > bitlminl[N << 1];
vector < int > bitrminr[N << 1];
void preparel(int idx , int val){
	vl[idx].emplace_back(val);
}
void preparer(int idx , int val){
	vr[idx].emplace_back(val);
}
void preparelminl(int idx , int val){
	idx += N;
	vlminl[idx].emplace_back(val);
}
void preparerminr(int idx , int val){
	vrminr[idx].emplace_back(val);
}

void buildl(int idx){
	if(!markl[idx]){
		markl[idx] = 1;
		sort(vl[idx].begin() , vl[idx].end());
		bitl[idx].clear();
		bitl[idx].resize(vl[idx].size() + 3 , 0);
	}
}
void buildr(int idx){
	if(!markr[idx]){
		markr[idx] = 1;
		sort(vr[idx].begin() , vr[idx].end());
		bitr[idx].resize(vr[idx].size() + 3 , 0);
	}
}
void buildlminl(int idx){
	idx += N;
	if(!marklminl[idx]){
		marklminl[idx] = 1;
		sort(vlminl[idx].begin() , vlminl[idx].end());
		bitlminl[idx].resize(vlminl[idx].size() + 3 , 0);
	}
}
void buildrminr(int idx){
	if(!markminr[idx]){
		markminr[idx] = 1;
		sort(vrminr[idx].begin() , vrminr[idx].end());
		bitrminr[idx].resize(vrminr[idx].size() + 3 , 0);
	}
}
int querypre(const vector < int > &bit , int idx){
	int res = 0;
	idx = min(idx , int(bit.size()) - 1);
	while(idx > 0){
		res += bit[idx];
		idx -= idx & -idx;
	}
	return res;
}
int querysuf(const vector < int > &bit , int idx){
	int res = 0;
	idx = max(idx , 1);
	while(idx < bit.size()){
		res += bit[idx];
		idx += idx & -idx;
	}
	return res;
}
void updatepre(vector < int > &bit , int idx){
	idx = max(idx , 1);
	while(idx < bit.size()){
		++bit[idx];
		idx += idx & -idx;
	}
}
void updatesuf(vector < int > &bit , int idx){
	idx = min(idx , int(bit.size()) - 1);
	while(idx > 0){
		++bit[idx];
		idx -= idx & -idx;
	}
}
int cntl(int idx , int val){
	int res = 0;
	if(idx >= 0 && idx < N){
		int x = lower_bound(vl[idx].begin() , vl[idx].end() , val) - vl[idx].begin();
		res = querysuf(bitl[idx] , x + 1);
	}
	return res;
}
int cntr(int idx , int val){
	int res = 0;
	if(idx >= 0 && idx < N){
		int x = lower_bound(vr[idx].begin() , vr[idx].end() , val + 1) - vr[idx].begin();
		res = querysuf(bitr[idx] , x + 1);
	}
	return res;
}
int cntlminl(int idx , int val){
	int res = 0;
	idx += N;
	if(idx >= 0 && idx < N + N){
		for(int it : vlminl[idx]){
			if(it < val){
				++res;
			}
		}
		int x = lower_bound(vlminl[idx].begin() , vlminl[idx].end() , val) - vlminl[idx].begin() - 1;
		res = querypre(bitlminl[idx] , x + 1);
	}
	return res;
}
int cntrminr(int idx , int val){
	int res = 0;
	if(idx >= 0 && idx < N + N){
		for(int it : vrminr[idx]){
			if(it <= val){
				++res;
			}
		}
		int x = lower_bound(vrminr[idx].begin() , vrminr[idx].end() , val + 1) - vrminr[idx].begin() - 1;
		res = querypre(bitrminr[idx] , x + 1);
	}
	return res;
}
void updatel(int idx , int val){
	int x = lower_bound(vl[idx].begin() , vl[idx].end() , val) - vl[idx].begin();
	updatesuf(bitl[idx] , x + 1);
}
void updater(int idx , int val){
	int x = lower_bound(vr[idx].begin() , vr[idx].end() , val) - vr[idx].begin();
	updatesuf(bitr[idx] , x + 1);
}
void updatelminl(int idx , int val){
	idx += N;
	int x = lower_bound(vlminl[idx].begin() , vlminl[idx].end() , val) - vlminl[idx].begin();
	updatepre(bitlminl[idx] , x + 1);
}
void updaterminr(int idx , int val){
	int x = lower_bound(vrminr[idx].begin() , vrminr[idx].end() , val) - vrminr[idx].begin();
	updatepre(bitrminr[idx] , x + 1);
}
void clearl(int idx){
	vl[idx].clear();
	markl[idx] = 0;
	bitl[idx].clear();
}
void clearr(int idx){
	vr[idx].clear();
	markr[idx] = 0;
	bitr[idx].clear();
}
void clearlminl(int idx){
	idx += N;
	vlminl[idx].clear();
	marklminl[idx] = 0;
	bitlminl[idx].clear();
}
void clearrminr(int idx){
	vrminr[idx].clear();
	markminr[idx] = 0;
	bitrminr[idx].clear();
}
void solve(int l , int r){
	if(l == r){
		++ans;
		return;
	}
	int mid = l + r >> 1;
	solve(l , mid);
	solve(mid + 1 , r);
	int mx = 0;
	int mn = N;
	siz = 0;
	for(int i = mid ; i >= l ; --i){
		mx = max(mx , arr[i]);
		mn = min(mn , arr[i]);
		tmp[++siz] = data(mx , mn , i , 'L');
	}
	mx = 0;
	mn = N;
	for(int i = mid + 1 ; i <= r ; ++i){
		mx = max(mx , arr[i]);
		mn = min(mn , arr[i]);
		tmp[++siz] = data(mx , mn , i , 'R');
	}
	sort(tmp + 1 , tmp + 1 + siz);
	for(int i = 1 ; i <= siz ; ++i){
		data cur = tmp[i];
		if(cur.type == 'L'){
			preparel(cur.id , cur.mn);
			preparelminl(cur.id - cur.mn , cur.mn);
		}
		else{
			preparerminr(cur.id + cur.mn , cur.mn);
			preparer(cur.id , cur.mn); 
		}
	}
	for(int i = 1 ; i <= siz ; ++i){
		data cur = tmp[i];
		if(cur.type == 'L'){
			buildl(cur.id);
			buildlminl(cur.id - cur.mn);
		}
		else{
			buildrminr(cur.id + cur.mn);
			buildr(cur.id); 
		}
	}
	for(int i = 1 ; i <= siz ; ++i){
		data cur = tmp[i];
		if(cur.type == 'L'){
			ans += cntrminr(cur.id + cur.mx , cur.mn); 
			ans += cntr(cur.id + cur.mx - cur.mn , cur.mn);
			updatel(cur.id , cur.mn);
			updatelminl(cur.id - cur.mn , cur.mn);
		}
		else{
			ans += cntl(cur.id - cur.mx + cur.mn , cur.mn);
			ans += cntlminl(cur.id - cur.mx , cur.mn);
			updaterminr(cur.id + cur.mn , cur.mn);
			updater(cur.id , cur.mn); 
		}
	}
	for(int i = 1 ; i <= siz ; ++i){
		data cur = tmp[i];
		if(cur.type == 'L'){
			clearl(cur.id);
			clearlminl(cur.id - cur.mn);
		}
		else{
			clearrminr(cur.id + cur.mn);
			clearr(cur.id); 
		}
	}
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		int a , b;
		scanf("%d %d" , &a , &b);
		arr[a] = b;
	}
	solve(1 , n);
	printf("%lld\n" , ans);
}