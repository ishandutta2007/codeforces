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

int len, ok[N], del[N];
char s[N];

void MAIN(){
	scanf("%d%s", &len, s + 1);
	for(int i = 1; i <= len; ++i){
        if(s[i - 1] == 'g' && s[i] == 'o'){
            if(ok[i - 2] || del[i - 2]) del[i] = del[i - 1] = true;
        }
        if(s[i] == 'o'){
            ok[i] = true;
            continue;
        }

	}
	for(int i = 1; i <= len; ++i)
        if(!del[i] && ok[i] && del[i + 1] && del[i + 2]) printf("***");
        else
            if(!del[i]) printf("%c", s[i]);
}