//sobskdrbhvk
//remember the flight, the bird dies ):(

//hame zadan ino, ma ham bezanim, hamrang e jamaat shim :p
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

const int maxn = 1e5 + 85 - 69,
	  maxl = 18;
pii mnsp[maxl][maxn];
int gcdsp[maxl][maxn],
	pp[maxn],
	le[maxn],
	ri[maxn],
	a[maxn],
	n, q;

pii mnmerge(pii le, pii ri){
	if(a[le.L] == a[ri.L])
		return MP(le.L, le.R + ri.R);
	return a[le.L] < a[ri.L] ? le : ri;
}

int getgcd(int st, int en){
	int f = pp[en - st + 1];
	return __gcd(gcdsp[f][st], gcdsp[f][en - (1 << f) + 1]);
}

pii getmn(int st, int en){
	if(st > en) return MP(n, 1);
	int f = pp[en - st + 1];
	return mnmerge(mnsp[f][st], getmn(st + (1 << f), en));
}

int main(){
	pp[0] = -1;
	for(int i = 1; i < maxn; i++)
		pp[i] = pp[i>>1]+1;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", a + i), mnsp[0][i] = MP(i, 1), gcdsp[0][i] = a[i];
	a[n] = 1000 * 1000 * 1000 + 100;
	for(int i = 1; i < maxl; i++)
		for(int j = 0; j + (1 << i) <= n; j++){
			mnsp[i][j] = mnmerge(mnsp[i - 1][j], mnsp[i - 1][j + (1 << (i-1))]);
			gcdsp[i][j] = __gcd(gcdsp[i - 1][j], gcdsp[i - 1][j + (1 << (i - 1))]);
		}
	for(int i = 0; i < n; i++){
		int lo = -1,
			hi = +i;
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if(getgcd(mid, i) % a[i]== 0)
				hi = mid;
			else
				lo = mid;
		}
		le[i] = hi;
		lo = i, hi = n;
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if(getgcd(i, mid) % a[i] == 0)
				lo = mid;
			else
				hi = mid;
		}
		ri[i] = lo;
	}
	scanf("%d", &q);
	while(q--){
		int fi, se;
		scanf("%d%d", &fi, &se);
		fi--, se--;
		auto mn = getmn(fi, se);
		if(le[mn.L] <= fi and ri[mn.L] >= se)
			printf("%d\n", se - fi + 1 - mn.R);
		else
			printf("%d\n", se - fi + 1);
	}
	return 0;
}