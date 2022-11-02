#include <bits/stdc++.h>

#define int long long
using namespace std;

int A[100001];
int s[100001];
int res[100001];
const int B = 400;
int n, m, k;

struct Query{
	int l, r, id;
	
	bool operator< (const Query& o) const{
		return r < o.r;
	}
};

int cnt[1 << 20];
int ans = 0;

void add(int x){
	ans += cnt[k ^ s[x]];
	cnt[s[x]]++;
}

void del(int x){
	cnt[s[x]]--;
	ans -= cnt[k ^ s[x]];
}

int32_t main(){
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		cin >> A[i + 1];
		s[i + 1] = s[i] ^ A[i + 1];
	}
	
	vector<vector<Query>> blocks(n / B + 2, vector<Query>());
	for(int i = 0; i < m; i++){
		int l, r;
		cin >> l >> r;
		l--;
		blocks[l / B].push_back({l, r, i});
	}
	
	for(auto &i : blocks){
		sort(i.begin(), i.end());
	}
	
	int l = 0, r = -1;
	for(int i = 0; i < n / B + 2; i++){
		for(auto i : blocks[i]){
			while(r > i.r){
				del(r);
				r--;
			}
			
			while(r < i.r){
				r++;
				add(r);
			}
			
			while(l > i.l){
				l--;
				add(l);
			}
			
			while(l < i.l){
				del(l);
				l++;
			}
			res[i.id] = ans;
		}
	}
	
	for(int i = 0; i < m; i++){
		cout << res[i] << endl;
	}
}