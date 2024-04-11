#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 13;
const int A = 1e6 + 13;
int a[N], k[A], ans[N];

const int B = 600;
struct query{
	int l, r, id;
	bool operator< (const query& o) const{
		return l / B < o.l / B || l / B == o.l / B && (l / B % 2 ? o.r < r : o.r > r);
	}
};
vector<query> Q;

int cans = 0;
void add(int idx){
	cans -= k[a[idx]] * k[a[idx]] * a[idx];
	k[a[idx]]++;
	cans += k[a[idx]] * k[a[idx]] * a[idx];
}

void del(int idx){
	cans -= k[a[idx]] * k[a[idx]] * a[idx];
	k[a[idx]]--;
	cans += k[a[idx]] * k[a[idx]] * a[idx];
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r; 
		l--; r--;
		Q.push_back({l, r, i});
	}
	sort(Q.begin(), Q.end());
	
	int l = 0, r = -1;
	for(auto q : Q){
		while(l > q.l) add(--l);
		while(l < q.l) del(l++);
		while(r < q.r) add(++r);
		while(r > q.r) del(r--);
		ans[q.id] = cans;
	}
	
	for(int i = 0; i < q; i++){
		cout << ans[i] << '\n';
	}
}