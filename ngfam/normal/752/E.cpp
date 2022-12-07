/*** Riven is not just my life :) ***/

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
const llint N = 2e7 + 1, mod = 1e9 + 7;

int n, a[N], ans = -1, cnt[N];
llint k;

bool check(int val){
    llint now = 0;

    memset(cnt, 0, sizeof cnt);
    cnt[val] = 1;
    //cout << cnt[];
    for(int i = val + 1; i < N - 1; ++i){
        cnt[i] = max(cnt[i - 1], cnt[i >> 1] + cnt[i - (i >> 1)]);
    }

    for(int i = 1; i <= n; ++i){
        now += cnt[a[i]];
       // cout << now << endl;
    }
    return now >= k;
}

void MAIN(){
    scanf("%d%lld", &n, &k);
    for(int i = 1; i <= n; ++i){
        scanf("%d", a + i);
    }

    int low = 1, high = 1e7;
   // cout << check(5);
    //return;
    //cout << cnt[2];

    /*for(int i = 1; i <= high; ++i){
        cnt[i] = max(cnt[i], cnt[i - 1]);
    }*/
   // cnt[1] = 1;
    //check(4);
    while(low <= high){
        int val = (low + high) >> 1;
        //cout << low << " " << high << " " << val << endl;
        if(check(val)){
            ans = max(ans, val);
            low = val + 1;
        }
        else{
            high = val - 1;
        }
    }

    //cout << cnt[1];

    printf("%d", ans);
}