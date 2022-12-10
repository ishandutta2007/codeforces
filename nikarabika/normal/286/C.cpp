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

const int maxn = 1e6 + 85 - 69;
int a[maxn],
	ans[maxn],
	n, t;
bool mark[maxn];
int stc[maxn], sz;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", a + i);
	scanf("%d", &t);
	while(t--){
		int fi;
		scanf("%d", &fi);
		fi--;
		mark[fi] = true;
	}
	reverse(a, a + n);
	reverse(mark, mark + n);
	for(int i = 0; i < n; i++){
		if(mark[i]){
			ans[i] = -a[i];
			stc[sz++] = (a[i]);
		}
		else if(sz and stc[sz - 1] == a[i])
			ans[i] = +a[i], sz--;
		else
			ans[i] = -a[i], stc[sz++] = (a[i]);
	}
	if(sz){
		printf("NO\n");
		return 0;
	}
	reverse(ans, ans + n);
	printf("YES\n");
	for(int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}