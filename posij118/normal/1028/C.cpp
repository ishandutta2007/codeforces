#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, cur, row, rowf, colf, col, a, b, c, d, ptr1, ptr2;

    ptr1 = 0;
    ptr2 = 0;
    cin >> n;
    int ro[n];
    int co[n];
    int vis[n];
    fill(ro, ro + n, 1e9 + 7);
    fill(co, co + n, 1e9 + 7);

    pair<pair<int, int>, int> x[2*n];
    pair<pair<int, int>, int> y[2*n];
    for(int i = 0; i<n; i++){
        cin >> a >> b >> c >> d;
        x[2*i] = make_pair(make_pair(a, 1),i);
        x[2*i + 1] = make_pair(make_pair(c + 1,  - 1), i);
        y[2*i] = make_pair(make_pair(b, 1), i);
        y[2*i + 1] = make_pair(make_pair(d + 1,  - 1), i);
    }

    sort(x, x + 2*n);
    sort(y, y + 2*n);
    cur = 0;
    fill(vis, vis + n, 0);

    for(int i = 0; i<2*n; i++){
        if(i != 0){
            if(x[i].first.first != x[i-1].first.first){
                if(cur >= n - 1){
                    for(int j = 0; j<n; j++){
                        if(vis[j] == 0) ro[j] = x[i].first.first - 1;
                    }

                }
                if(cur >= n){
                    for(int j = 0; j<n; j++){
                        ro[j] = x[i].first.first - 1;
                    }
                }
            }
        }

        cur += x[i].first.second;
        vis[x[i].second] += x[i].first.second;

    }

    cur = 0;
    fill(vis, vis + n, 0);
    for(int i = 0; i<2*n; i++){
        if(i != 0){
            if(y[i].first.first != y[i-1].first.first){
                if(cur >= n - 1){
                    for(int j = 0; j<n; j++){
                        if(vis[j] == 0) co[j] = y[i].first.first - 1;
                    }

                }
                if(cur >= n){
                    for(int j = 0; j<n; j++){
                        co[j] = y[i].first.first - 1;
                    }
                }
            }
        }

        cur+=y[i].first.second;
        vis[y[i].second] += y[i].first.second;

    }
    
    for(int i = 0; i<n; i++){
        if(ro[i] < 1e9 + 7 && co[i] < 1e9 +7){
            cout << ro[i] << " " << co[i];
            return 0;
        }

    }




}