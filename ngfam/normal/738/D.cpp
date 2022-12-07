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

int n, a, b, k, pos, del[N];
char s[N];

void MAIN(){
	scanf("%d%d%d%d", &n, &a, &b, &k);
	scanf("%s", s + 1);

	int cnt = 0;
	for(int i = 1; i <= n; ++i){
        if(a == 0) break;
        if(s[i] == '0') ++cnt;
        else cnt = 0;

        if(cnt == b){
            pos = i;
            s[i] = '1';
            cnt = 0;
            --a;
        }
	}
	del[pos] = 1;


	int ans = 1;
	cnt = 0;

	for(int i = 1; i <= n; ++i){
        if(s[i] == '0') ++cnt;
        else cnt = 0;

        if(cnt == b){
            del[i] = 1;
            cnt = 0;
            ++ans;
        }
	}

	printf("%d\n", ans);
	for(int i = 1; i <= n; ++i){
        if(del[i]){
            printf("%d ", i);
        }
	}
}