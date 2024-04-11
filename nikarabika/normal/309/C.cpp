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

const int maxn = 1000 * 1000;
int a[maxn], b[maxn], n, m;
vector<int> vec;

int main(){
	vec.reserve(1 << 20);
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", a + i);
	for(int i = 0; i < m; i++)
		scanf("%d", b + i);
	for(int i = 30; i >= 0; i--)
		for(int j = 0; j < n; j++)
			if((a[j] >> i) & 1)
				vec.PB(i);
	sort(b, b + m);
	int p;
	for(p = 0; p < m; p++){
		while(sz(vec) and vec.back() < b[p])
			vec.pop_back();
		if(!sz(vec))
			break;
		int x = vec.back();
		vec.pop_back();
		for(int i = x - 1; i >= b[p]; i--)
			vec.PB(i);
	}
	printf("%d", p);
	return 0;
}