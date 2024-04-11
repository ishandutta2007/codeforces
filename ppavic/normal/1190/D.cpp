#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef pii pt;
typedef vector < int > vi;
typedef set < int > si;
typedef long double ld;

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const ld PI = 3.1415926535;
const ld EPS = 1e-9;

int n, m;
int x[N], y[N], loga[N];
vi svi[N], saz;

void add(int x){
	x += 10; //printf("ubacujem %d\n", x - 10);
	for(; x < N; x += x & -x)
		loga[x]++;
}

int get(int l, int r){
	if(l > r) return 0;
	//printf(" [ %d %d ] => ", l, r);
	l += 9, r += 10;
	int ret = 0;
	for(; l ; l -= l & -l) ret -= loga[l];
	for(; r ; r -= r & -r) ret += loga[r];
	//printf("%d\n", ret);
	return ret;
}

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%d%d", x + i, y + i);
		saz.PB(x[i]);
	}
	sort(saz.begin(), saz.end());
	saz.erase(unique(saz.begin(), saz.end()), saz.end());
	m = (int)saz.size();
	vector < pt > v;
	for(int i = 0;i < n;i++){
		x[i] = lower_bound(saz.begin(), saz.end(), x[i]) - saz.begin();
		v.PB({y[i], x[i]});
	}
	sort(v.rbegin(), v.rend());
	ll sol = 0;
	for(int i = 0;i < n;){
		int cur = v[i].X;
		vector < int > tmp;
		while(v[i].X == cur){
			tmp.PB(v[i++].Y); 
			if(!get(tmp.back(), tmp.back()))
				add(tmp.back());
		}
		reverse(tmp.begin(), tmp.end());
		tmp.PB(m);
		for(int j = 0;j + 1 < tmp.size();j++){
			//printf("(%d %d) %d * %d\n", cur, tmp[j], get(0, tmp[j]), get(tmp[j], tmp[j + 1] - 1));
			sol += (ll)get(0, tmp[j]) * (ll)get(tmp[j], tmp[j + 1] - 1);
		}
	}
	printf("%lld\n", sol);
}