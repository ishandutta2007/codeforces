#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int query(int x){
    printf("? %d\n", x);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

int _search(){
    int l = 1, r = 1e8, ret = 1e8;
    while(l<=r){
        int m = (l+r)>>1;
        if (query(m)==1) r = m-1, ret = m;
        else l = m+1;
    }
    return ret;
}

int main(){
    int n;
    scanf("%d", &n);
    int L = _search();
    int ans = L;

    for (int i=2;i<=n;i++){
        int h = query(L/i);
        if (h==0) continue;
        ans = min(ans, h*(L/i));
    }
    printf("! %d\n", ans);
    fflush(stdout);
    return 0;
}