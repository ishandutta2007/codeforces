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

char s[N];
int n, m, k, cnt[N][30];

stack < char > st;

void MAIN(){
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1; i <= n; ++i){
        for(int j = 0; j < 26; ++j){
            cnt[i][j] = cnt[i - 1][j];
        }
        if(s[i] != '?') ++cnt[i][s[i] - 'A'];
        if(i > 26) --cnt[i][s[i - 26] - 'A'];

        if(i < 26) continue;

        bool ok = false;
        for(int j = 0; j < 26; ++j){
            if(cnt[i][j] > 1){
                ok = true;
                break;
            }
        }

        if(ok == false){
            for(int j = 0; j < 26; ++j){
                if(cnt[i][j] == 0) st.push(j + 'A');
            }

            for(int j = i - 26 + 1; j <= i; ++j){
                if(s[j] == '?'){
                    s[j] = st.top();
                    st.pop();
                }
            }

            for(int j = 1; j <= n; ++j){
                if(s[j] == '?'){
                    s[j] = 'Z';
                }
            }
            printf("%s", s + 1);
            return;
        }
	}
	puts("-1");
}