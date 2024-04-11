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
const llint N = 15e2 + 1, mod = 1e9 + 7;

char s[N], tmp[N]; bool ok[N];
int cnt[N], n, k, trie[N * N][30], m;

void MAIN(){
    memset(trie, -1, sizeof trie);
    scanf("%s%s%d", s + 1, tmp, &k);
    n = strlen(s + 1);

    for(int i = 0; i < 26; ++i)
        ok[i] = tmp[i] - '0';

    for(int i = 1; i <= n; ++i)
        cnt[i] = cnt[i - 1] + (!ok[s[i] - 'a']);
    int ans = 0;

    //trie[0][]

    for(int i = 1; i <= n; ++i){
        int pos = 1;
        for(; pos < i; ++pos)
            if(cnt[i] - cnt[pos - 1] <= k)
                break;

        if(cnt[i] - cnt[pos - 1] > k) continue;
        //cerr << cnt[i] - cnt[pos - 2] << endl;
        int cur = 0;
        for(int j = i; j >= pos; --j){
            int c = s[j] - 'a';
            if(trie[cur][c] == -1){
                ++ans;
                trie[cur][c] = ++m;
            }
            cur = trie[cur][c];
        }
    }
    printf("%d", ans);
}