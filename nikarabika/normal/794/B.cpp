//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

int n;
LD H;

LD get(LD a, LD b, LD c){
	return (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
}

void solve(LD d = 1, LD h = H, int cnt = n) {
	if(cnt == 1) return;
	LD s = d * h / 2 / cnt;
	LD l = get(-d, 0, h * d * h - 2 * h * s);
	LD x = l * d / h;
	solve(x, l, cnt - 1);
	cout << l << ' ';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> H;
	cout.precision(12);
	cout<<fixed;
	solve();
	cout << endl;
	return 0;
}