#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;

const int N = 1e6 + 7;
int n;

vector < pair < int, int > > vc;
int cnt[N]; 

void Push(int x, int y) {
	assert(cnt[x] > 0);
	cnt[x] -= 1;
	assert(cnt[y] > 0);
	cnt[y] -= 1;
	cnt[x + y] += 1;
	cnt[abs(x - y)] += 1;
	vc.push_back({x, y});
}

int solve(int n, int mut) {
	if(n <= 2) 
		return n; 
	
	int up = 1;
	while (up < n) 
		up <<= 1; 
	
//	cout << "up = " << up << '\n';
	
	if(n == up)	
		return solve(n - 1, mut);
	
	auto pb = [&] (int x, int y) {
		Push(x * mut, y * mut);
		return ;
	};
	
	if(n == 3) {
		pb(1, 3);
		pb(2, 2);
		return up;
	}
	
	if(n == 5) {
		pb(3, 5);
		pb(2, 2);
		return up;
	}
	
	if(n == 6) {
		pb(2, 6);
		pb(3, 5);
		pb(4, 4);
		return up;
	}
	
	int x = up - n;
	solve(x - 1, mut);
	int t = up - x * 2;
	L(i, x, up / 2 - 1) 
		pb(i, up - i);
	solve(t / 2, mut * 2);
	return up; 
}  

void Main () {
	cin >> n;
	if(n == 2) {
		cout << -1 << '\n';
		return ;
	}
	
	L(i, 1, n) cnt[i] += 1;
	
	vc.clear();
	int t = solve(n, 1);
	
//	cout << "cnt = " << cnt[0] << endl;
	
	assert(cnt[0]); 
	for(int i = 1; i < t; i <<= 1) {
		while(cnt[i]) {
			if(cnt[i] > 1) Push(i, i);
			else Push(i, 0), Push(i, i);
		}
	}
	
	while(cnt[0]) 
		Push(t, 0);
	
	cout << sz(vc) << '\n';
	for(auto u : vc) 
		cout << u.first << ' ' << u.second << '\n';
		
//	L(i, 0, t) if(cnt[i]) cout << "i = " << i << '\n';
		
	L(i, 0, t) cnt[i] = 0;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) Main ();
	
	return 0;
}