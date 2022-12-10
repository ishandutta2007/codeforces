//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
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

const int maxn = 80 * 1000,
	  maxl = 32;
const int maxb = maxn / maxl + 1;
int func[maxn],
	xof[maxn],
	yof[maxn],
	fir[maxn],
	a[maxn],
	ord[maxn],
	mxin[maxn],
	n, s;
bool mark[maxn];
vector<int> vec[maxn];

struct Bitset{
	int a[maxb];
	Bitset(){
		memset(a, 0, sizeof a);
	}
	void set(int pos, bool val = true){
		int x = xof[pos],
			y = yof[pos];
		a[x] ^= (((a[x] >> y) & 1) xor val) << y;
		return;
	}
	int &operator[](int i){return a[i];}
	int most(void){
		for(int i = 0; i < maxb; i++)
			if(a[i]){
				int ret = __builtin_ffs(a[i]) - 1;
				a[i] ^= 1 << ret;
				return ret + (i << 5);
			}
		return -1;
	}
} dp[2], tmp;

Bitset operator|(Bitset &A, Bitset &B){
	Bitset ret;
	for(int i = 0; i < maxb; ++i)
		ret[i] = A[i] | B[i];
	return ret;
}

Bitset operator^(Bitset &A, Bitset &B){
	Bitset ret;
	for(int i = 0; i < maxb; ++i)
		ret[i] = A[i] ^ B[i];
	return ret;
}

Bitset operator<<(Bitset &A, int len){
	int x = xof[len],
		y = yof[len],
		yy = 32 - y;
	Bitset ret;
	if(y == 0){
		for(int i = 0; i + x < maxb; i++)
			ret[i + x] = A[i];
		return ret;
	}
	for(int i = 0; i + x < maxb; i++){
		int val = (A[i] & func[yy])<<y;
		ret[i + x] += val;
		val = (A[i] >> yy) & func[y];
		if(i + x + 1 < maxb) ret[i + x + 1] += val;
	}
	return ret;
}

bool cmp(int i, int j){
	return a[i] > a[j];
}

void show(Bitset A){
	for(int j = 31; j >= 0; j--)
		cout << ((A[0]>>j) & 1);
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 1; i <= maxl; i++)
		func[i] = (func[i - 1]<<1)|1;
	for(int i = 0; i < maxn; i++)
		xof[i] = i >> 5, yof[i] = i & 31;
	cin >> n >> s;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		ord[i] = i;
	}
	sort(ord, ord + n, cmp);
	if(a[ord[0]] > s){
		cout << -1 << '\n';
		return 0;
	}
	s -= a[ord[0]];
	memset(fir, -1, sizeof fir);
	int pre = 0, cur = 1;
	dp[cur].set(0);
	for(int i = 1; i < n; i++){
		int val = a[ord[i]];
		swap(pre, cur);
		tmp = (dp[pre] << val);
		dp[cur] = dp[pre] | tmp;
		tmp = dp[cur] ^ dp[pre];
		while(1){
			int pos = tmp.most();
			if(pos == -1) break;
			fir[pos] = i;
		}
		//cout << dp[cur][0] << ' ' << (dp[cur] << 1)[0] << endl;
		//show(dp[cur]);
		//show(dp[cur] << 1);
	}
	if(s != 0 and fir[s] == -1){
		cout << -1 << '\n';
		return 0;
	}
	int ptr = s;
	mark[0] = true;
	while(ptr){
		mark[fir[ptr]] = true;
		ptr -= a[ord[fir[ptr]]];
	}
	for(int i = 1; i < n; i++){
		if(!mark[i]){
			smax(mxin[ord[i - 1]], a[ord[i]]);
			vec[ord[i - 1]].PB(ord[i]);
		}
	}
	for(int i = 0; i < n; i++){
		cout << a[i] - mxin[i] << ' '
			<< sz(vec[i]) << ' ';
		for(auto val : vec[i])
			cout << val+1 << ' ';
		cout << '\n';
	}
	return 0;
}