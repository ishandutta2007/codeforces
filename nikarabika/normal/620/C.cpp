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

const int maxn = 3e5 + 10;
int n, a[maxn], NEXT[maxn], address[maxn];
vector<int> all;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", a + i);
		all.PB(a[i]);
	}
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	for(int i = 0; i < n; i++)
		a[i] = lower_bound(all(all), a[i]) - all.begin();
	memset(NEXT, -1, sizeof NEXT);
	memset(address, -1, sizeof address);
	for(int i = 0; i < n; i++){
		if(address[a[i]] != -1)
			NEXT[i] = address[a[i]];
		address[a[i]] = i;
	}
	vector<pii> ans;
	for(int i = 0; i < n; i++){
		int p = i;
		while(p < n and NEXT[p] < i) p++;
		if(p == n){
			if(sz(ans) == 0){
				printf("-1\n");
				return 0;
			}
			ans[sz(ans) - 1].R = n - 1;
			i = n - 1;
		}
		else
			ans.PB(MP(i, p)), i = p;
	}
	printf("%d\n", sz(ans));
	for(auto seg : ans)
		printf("%d %d\n", seg.L + 1, seg.R + 1);
	return 0;
}