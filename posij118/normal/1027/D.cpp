#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, ans, mi, ptr, x, skap;
    ans = 0;
    cin >> n;

    int a[n], c[n];
    bool vis[n];
    set<int> vert;
    vector<int> path;
    fill(vis, vis + n, 0);
    for(int i = 0; i<n; i++){
        cin >> c[i];
    }

    for(int i = 0; i<n; i++){
        cin >> a[i];
        a[i]--;
    }

    for(int i = 0; i<n; i++){
        vert.clear();
        path.clear();
        mi = 1e9;
        ptr = i;
        skap = 0;
        while(vis[ptr] == 0){
            path.push_back(ptr);
            if(vert.count(ptr)){
                x = ptr;
                for(int j = path.size() - 1; j>=0; j--){
                    mi = min(mi, c[path[j]]);
                    if(j == path.size() - 1) continue;
                    if(path[j] == x) break;
                }

                ans += mi;
                skap = 1;

            }

            if(skap == 1) break;

            vert.insert(ptr);
            ptr = a[ptr];
        }

        for(int i = 0; i<path.size(); i++){
            vis[path[i]] = 1;
        }
    }

    cout << ans;

}