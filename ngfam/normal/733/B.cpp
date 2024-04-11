/* Riven is not just my life :) */

#include <bits/stdc++.h>
#define prob "test"
typedef long long llint;
using namespace std;
void MAIN();
int main(){
    #ifndef ONLINE_JUDGE
        freopen(prob".inp","r",stdin);
      //  freopen(prob".out","w",stdout);
    #endif
    MAIN();
    return 0;
}
const llint N = 1e6 + 1, mod = 1e9 + 7;
typedef pair<int,int> ii;

ii a[N];
int n, sum;

void MAIN(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
        scanf("%d%d", &a[i].first, &a[i].second);
        sum += a[i].first - a[i].second;
	}
	int ans = 0, pos = abs(sum);
	for(int i = 1; i <= n; ++i){
         if(pos < abs(sum + (a[i].second - a[i].first) * 2)){
            ans = i;
            pos = abs(sum + (a[i].second - a[i].first) * 2);
         }

	}
	printf("%d", ans);
}