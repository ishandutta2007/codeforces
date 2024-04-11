#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 5;
 
inline uint32_t two(int8_t x){
	return ((uint32_t)1)<<x;
}
 
struct trie{
	uint32_t cnt;
	trie *lc, *rc;
	trie():cnt(0),lc(0),rc(0){}
	void pull(){
		cnt = 0;
		if(lc) cnt += lc->cnt;
		if(rc) cnt += rc->cnt;
	}
	void insert(uint32_t x, int8_t h){
		if(h == -1) {
			cnt++; return;
		}
		if(x & two(h)){
			if(!rc) rc = new trie();
			rc->insert(x, h-1);
		}else{
			if(!lc) lc = new trie();
			lc->insert(x, h-1);
		}
		pull();
	}
	uint32_t count(uint32_t m, uint32_t x, int8_t h){
		// xor m >= x
		if(h == -1) return cnt;
		if(m & two(h)) swap(lc, rc);
		uint32_t ret = 0;
		if(x & two(h)){
			if(rc) ret = rc->count(m, x, h-1);
		}else{
			if(rc) ret += rc->cnt;
			if(lc) ret += lc->count(m, x, h-1);
		}
		if(m & two(h)) swap(lc, rc);
		return ret;
	}
};
 
uint32_t arr[N];
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k; cin >> n >> k;
	for(int i=1;i<=n;i++)
		cin >> arr[i];
	uint32_t x = 0;
	int64_t ans = 0;
	auto rt = new trie();
	for(int i=1;i<=n;i++){
		rt->insert(x, 30);
		x ^= arr[i];
		ans += rt->count(x, k, 30);
	}
	cout << ans << '\n';
}