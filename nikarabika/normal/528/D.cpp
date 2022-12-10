//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef complex<LD> point;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()
#define X real()
#define Y imag()
#define PI 3.1415926

const int maxn = 1 << 19,
	  maxl = 20;
point vec[maxl][maxn],
	  tmp[maxn];
LD func[maxl][2][2];
bool can[4][maxn];
int n, m, k, sz;
int sum[maxn];
string s, t;

void fft(bool invert, int l = 0, int r = sz, int id = 0){
	int n = r - l,
		mid = (l + r) >> 1;
	if(n == 1) return;
	for(int i = 0; i < n / 2; i++){
		vec[id + 1][l + i] = vec[id][l + (i<<1)];
		vec[id + 1][mid + i] = vec[id][l + (i<<1|1)];
	}
	fft(invert, l, mid, id + 1);
	fft(invert, mid, r, id + 1);
	point w(1), wn(func[id][invert][0], func[id][invert][1]);
	for(int i = 0; i < n / 2; i++){
		vec[id][l + i] = vec[id + 1][l + i] + w * vec[id + 1][mid + i];
		vec[id][mid + i] = vec[id + 1][l + i] - w * vec[id + 1][mid + i];
		if(invert) vec[id][l + i] /= 2, vec[id][mid + i] /= 2;
		w *= wn;
	}
	return;
}

void solve(char c, int id){
	memset(sum, 0, sizeof sum);
	for(int i = 0; i < n; i++)
		if(s[i] == c)
			sum[max(0, i - k)]++, sum[min(n - 1, i + k) + 1]--;
	for(int i = 0; i + 1 < n; i++)
		sum[i + 1] += sum[i];
	for(int i = 0; i < sz; i++)
		if(i < n) vec[0][n - i - 1] = point(!bool(sum[i]), 0);
		else vec[0][i] = point(0, 0);
	fft(false);
	memcpy(tmp, vec[0], sizeof vec[0]);
	for(int i = 0; i < sz; i++)
		if(i < m) vec[0][i] = point(t[i] == c, 0);
		else vec[0][i] = point(0, 0);
	fft(false);
	for(int i = 0; i < sz; i++)
		vec[0][i] *= tmp[i];
	fft(true);
	for(int i = 0; i < n; i++)
		can[id][i] = !bool(int(vec[0][n - i - 1].X + .5));
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k
		>> s
		>> t;
	sz = 1;
	while(sz < n) sz <<= 1;
	for(int i = 0; (1 << i) <= sz; i++)
		for(int j = 0; j < 2; j++){
			LD ang = 2 * PI / (sz / (1 << i)) * (j ? -1 : +1);
			func[i][j][0] = cos(ang);
			func[i][j][1] = sin(ang);
		}
	solve('A', 0);
	solve('C', 1);
	solve('G', 2);
	solve('T', 3);
	int ans = 0;
	for(int i = 0; i <= n - m; i++){
		bool val = true;
		for(int j = 0; j < 4; j++)
			val &= can[j][i];
		ans += val;
	}
	cout << ans << '\n';
	return 0;
}