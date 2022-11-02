#include <bits/stdc++.h>
using namespace std;
vector<int> seg;

int main(){
    seg.resize(1 << 20);
    vector<int> ans;
    int n, x, y, z, cur, skap;
    cin >> n;

    int a[n], b[n], c[n], d[n];
    pair<int, int> comp[4*n];

    for(int i = 0; i<n; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        comp[4*i] = make_pair(a[i], 4*i);
        comp[4*i + 1] = make_pair(b[i], 4*i + 1);
        comp[4*i + 2] = make_pair(c[i], 4*i + 2);
        comp[4*i + 3] = make_pair(d[i], 4*i + 3);
    }

    queue<int> bfs;
    map<int, int> vis;
    for(int i = 0; i<n; i++){
        vis[i] = 0;
    }
    int dist[n];
    int p[n];
    vector<pair<int, int > > val[4*n];
    int pt[4*n];
    fill(pt, pt + 4*n, 0);

    for(int i = 0; i<n; i++){
        if(a[i] == 0 && b[i] == 0){
            bfs.push(i);
            vis[i] = 1;
            p[i] = i;
            dist[i] = 0;
        }
    }

    sort(comp, comp + 4*n);
    int ptr = 0;
    for(int i = 0; i<4*n; i++){
        if(i != 0){
            if(comp[i].first > comp[i - 1].first) ptr++;
        }

        if(comp[i].second % 4 == 0){
            a[comp[i].second / 4] = ptr;
        }

        if(comp[i].second % 4 == 1){
            b[comp[i].second / 4] = ptr;
        }

        if(comp[i].second % 4 == 2){
            c[comp[i].second / 4] = ptr;
        }

        if(comp[i].second % 4 == 3){
            d[comp[i].second / 4] = ptr;
        }
    }

    for(int i = 0; i<4*n; i++){
        val[i].push_back(make_pair(1e9, -1));
    }

    for(int i = 0; i<n; i++){
        val[a[i]].push_back(make_pair(b[i], i));
    }

    for(int i = 0; i<4*n; i++){
        sort(val[i].begin(), val[i].end());
    }

    while(vis[val[0][pt[0]].second]) pt[0]++;

    fill(seg.begin(), seg.end(), 1e9);

    for(int i = 0; i<4*n; i++){
        x = (1 << 19) + i + 1;
        seg[x] = val[i][pt[i]].first;

        while(x > 0){
            x/=2;
            seg[x] = min(seg[2*x], seg[2*x + 1]);
        }
    }

    while(!bfs.empty()){
        x = bfs.front();
        bfs.pop();

        while(1){
            skap = 0;
            cur = -1;
            y = (1 << 19);
            z = (1 << 19) + c[x] + 2;

            while(y < z - 1){
                if(y % 2 == 0){
                    if(seg[y + 1] <= d[x]){
                        cur = y + 1;
                        skap = 1;
                        while(cur < (1 << 19)){
                            if(seg[2*cur] <= d[x]) cur*=2;
                            else cur = 2*cur + 1;
                        }

                        break;
                    }
                }

                if(z % 2 == 1){
                    if(seg[z - 1] <= d[x]){
                        cur = z - 1;
                        skap = 1;
                        while(cur < (1 << 19)){
                            if(seg[2*cur] <= d[x]) cur*=2;
                            else cur = 2*cur + 1;
                        }

                        break;
                    }
                }

                z/=2;
                y/=2;
            }

            if(skap == 0) break;

            else{
                y = cur;
                z = cur - (1 << 19) - 1;
                pt[z]++;
                seg[y] = val[z][pt[z]].first;

                while(y > 0){
                    y/=2;
                    seg[y] = min(seg[2*y], seg[2*y + 1]);
                }

                bfs.push(val[z][pt[z] - 1].second);
                p[val[z][pt[z] - 1].second] = x;
                dist[val[z][pt[z] - 1].second] = dist[x] + 1;
                vis[val[z][pt[z] - 1].second] = 1;
            }
        }

    }

    if(vis[n - 1] == 0) cout << -1;
    else{
        cout << dist[n - 1] + 1 << endl;
        x = n - 1;
        for(int i = 0; i<dist[n - 1] + 1; i++){
            ans.push_back(x);
            x = p[x];
        }

        reverse(ans.begin(), ans.end());
        for(int i = 0; i<ans.size(); i++){
            cout << ans[i] + 1 << " ";
        }
    }



}