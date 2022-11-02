#include <bits/stdc++.h>
#define int long long
#define inf (1LL << 60)
#define fi first
#define se second
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int A[100001];

vector<int> primes;

void genPrime(int n){
	for(int i = 2; i <= n; i++){
		bool Done = false;
		for(auto j : primes){
			if(i % j == 0){
				Done = true;
				break;
			}
		}
		if(!Done) primes.push_back(i);
	}
}

vector<int> pf(int x){
	if(x == 1) return {};
	vector<int> pf;
	for(auto i : primes){
		if(i * i > x){
			if(x != 1) pf.push_back(x);
			return pf;
		}
		if(x % i == 0){
			while(x % i == 0){
				x /= i;
			}
			pf.push_back(i);
		}
	}
	return pf;
}

int cnt[100001];
bool try_add(int v){
	bool fail = false;
	for(auto i : pf(v)){
		if(cnt[i] != 0){
			fail = true;
		}
	}
	return !fail;
}

void add(int v){
	for(auto i : pf(v)){
		cnt[i]++;
	}
}

void del(int v){
	for(auto i : pf(v)){
		cnt[i]--;
	}
}

int R[100001];
int st[100001][20];

int n, q;

void lift(){
	for(int i = 0; i <= n; i++){
		st[i][0] = R[i];
	}
	
	for(int j = 1; j < 20; j++){
		for(int i = 0; i <= n; i++){
			st[i][j] = st[st[i][j - 1]][j - 1];
//			cout << i << ' ' << j << ' ' << st[i][j] << endl;
		}
	}
}

int query(int l, int r){
	int res = 0;
	for(int j = 19; j >= 0; j--){
		if(st[l][j] <= r){
			l = st[l][j];
			res += (1 << j);
		}
	}
	return res + 1;
}

int l, r;
int32_t main(){
	ios_base::sync_with_stdio(false);
	genPrime(1000);
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	l = 0, r = -1;
	while(l != n){
		while(r + 1 <= n - 1 && try_add(A[r + 1])){
			add(A[++r]);
		}
		R[l] = r;
		del(A[l++]);
	}
	
	for(int i = 0; i < n; i++){
		R[i]++;
	}
	R[n] = n;
	lift();
	for(int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r;
		l--, r--;
		cout << query(l, r) << endl; 
	}
}