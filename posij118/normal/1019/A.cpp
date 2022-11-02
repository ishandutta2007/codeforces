#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, one, num, ptr, x, y;
    one = 0;
    long long ans = 1e18;
    cin >> n >> m;

    pair<int,int> p[n];
    long long cum;
    for(int i = 0; i<n; i++){
       cin >> x >> y;
       if(x == 1) one++;
       p[i] = make_pair(y, x - 1);
    }

    sort(p, p+n);
    int rem[m - 1];
    int val[m];
    fill(val, val + m, 0);
    for(int i = 0; i<n; i++){
        val[p[i].second]++;
    }

    int vis[n];


    for(int i = one; i<=n; i++){
        cum = 0;
        ptr = 0;
        num = one;
        for(int j = 1; j<m; j++){
            rem[j - 1] = max(0, val[j] - i + 1);
        }

        fill(vis, vis + n, 0);
        for(int j = 0; j<n; j++){
            if(p[j].second > 0){
                if(rem[p[j].second - 1] > 0){
                    rem[p[j].second - 1]--;
                    vis[j] = 1;
                    cum+=p[j].first;
                    num++;
                }
            }
        }

        while(num < i){
            if(p[ptr].second > 0){
                if(vis[ptr] == 0){
                    vis[ptr] = 1;
                    cum+=p[ptr].first;
                    num++;
                }
            }

            ptr++;
        }

        ans = min(ans, cum);
    }

    cout << ans;

}