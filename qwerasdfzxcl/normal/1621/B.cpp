#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    pair<int, int> L = {2e9, 0}, R = {-2e9, 0};

    int mn = 2e9;
    pair<int, int> cur = {-2e9, 2e9};
    for (int i=0;i<n;i++){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        if (x<L.first || (x==L.first && z<L.second)) L = {x, z};
        if (y>R.first || (y==R.first && z<R.second)) R = {y, z};

        if (x<mn) cur = {y, z}, mn = x;
        else if (x==mn){
            if (y>cur.first) cur = {y, z};
            else if (y==cur.first && z<cur.second) cur = {y, z};
        }

        int ans = 2e9;
        if (cur.first==R.first) ans = min(ans, cur.second);
        ans = min(ans, L.second+R.second);
        printf("%d\n", ans);
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}