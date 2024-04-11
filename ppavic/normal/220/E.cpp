#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef vector < int > vi;

const int N = 1e5 + 500;
int n, A[N];
ll k, cur;
vi saz;
int loga[N][2], siz[2];

void add(int x, int y, int k){
	siz[k] += y;
	for(x += 10; x < N ; x += x & -x)
		loga[x][k] += y;
}

int query(int x, int k){
	int ret = 0;
	for(x += 10; x ; x -= x & -x)
		ret += loga[x][k];
	return ret;
}

inline int rub(int x){
	return query(x - 1, 1) + siz[0] - query(x, 0);
}

int main(){
	scanf("%d%lld", &n, &k);
	for(int i = 0;i < n;i++){
		scanf("%d", A + i); saz.PB(A[i]);
	}
	sort(saz.begin(), saz.end());
	saz.erase(unique(saz.begin(), saz.end()), saz.end());
	for(int i = 0;i < n;i++)
		A[i] = lower_bound(saz.begin(), saz.end(), A[i]) - saz.begin();
	for(int i = 0;i < n;i++){
		cur += siz[1] - query(A[i], 1);
		add(A[i], 1, 1);
	}
	int l = 0, r = 0;
	ll ans = 0;
	for(;l < n;l++){
		if(l == r){
			cur -= rub(A[r]);
			add(A[r], -1, 1);
			r++;
		}
		cur += rub(A[l]);
		add(A[l], 1, 0);
		while(r < n && cur > k){
			cur -= rub(A[r]);
			add(A[r], -1, 1);
			r++;
		}
		ans += n - r;
	}
	printf("%lld\n", ans);
	return 0;
}