//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double LD;
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

const int maxn = 1e5 + 85 - 69;
LD a, d;
LD arr[maxn];
int n;

LD get(LD maxv){
	LD tmxv = maxv / a,
	   td = sqrt(2 * d / a);
	if(td <= tmxv) return td;
	LD dd = d - .5 * a * tmxv * tmxv;
	return dd / maxv + tmxv;
}

int main(){
	int x, y;
	scanf("%d%d%d", &n, &x, &y);
	a = x, d = y;
	for(int i = 0; i < n; i++){
		int fi, se;
		scanf("%d%d", &fi, &se);
		arr[i] = fi + get(se);
		if(i) smax(arr[i], arr[i - 1]);
	}
	for(int i = 0; i < n; i++)
		printf("%f\n", arr[i]);
	return 0;
}