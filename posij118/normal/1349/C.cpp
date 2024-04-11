#include <bits/stdc++.h>
using namespace std;

bool grid[1000][1000];
vector<vector<int> > dist;
bool vis[1000][1000];

int n, m, t;

vector<pair<int, int> > v;
queue<pair<int, int> > bfs;

int solve(int x, int y){
    vis[x][y] = 1;
    v.push_back({x, y});
    if(dist[x][y] != -1) return dist[x][y];

    int mi = 1e9;

    if(x - 1 >= 0){
        if(grid[x - 1][y] != grid[x][y]) { dist[x][y] = 0; return 0;}
        if(vis[x - 1][y] == 0) mi = min(mi, solve(x - 1, y));
    }

    if(x + 1 < n){
        if(grid[x + 1][y] != grid[x][y]) { dist[x][y] = 0; return 0;}
        if(vis[x + 1][y] == 0) mi = min(mi, solve(x + 1, y));
    }

    if(y - 1 >= 0){
        if(grid[x][y - 1] != grid[x][y]) { dist[x][y] = 0; return 0;}
        if(vis[x][y - 1] == 0) mi = min(mi, solve(x, y - 1));
    }

    if(y + 1 < m){
        if(grid[x][y + 1] != grid[x][y]) { dist[x][y] = 0; return 0;}
        if(vis[x][y + 1] == 0) mi = min(mi, solve(x, y + 1));
    }

    dist[x][y] = mi + 1;
    return mi + 1;
}

int main(){
    cin >> n >> m >> t;
    bool cnt0, cnt1;

    cnt0 = 0;
    cnt1 = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            char c;
            cin >> c;
            if(c == '0') grid[i][j] = 0;
            if(c == '1') grid[i][j] = 1;

            if((i + j) & 1) grid[i][j] ^= 1;
            if(grid[i][j] == 0) cnt0 = 1;
            else cnt1 = 1;

            vis[i][j] = 0;
        }
    }

    dist.resize(n);
    for(int i = 0; i<n; i++){
        dist[i].resize(m);
        for(int j = 0; j<m; j++){
            dist[i][j] = -1;
        }
    }

    if(cnt1 && cnt0){
        for(int x = 0; x<n; x++){
            for(int y = 0; y<m; y++){
                if(x - 1 >= 0){
                    if(grid[x - 1][y] != grid[x][y]) { dist[x][y] = 0; bfs.push({x, y}); vis[x][y] = 1;}
                    //if(vis[x - 1][y] == 0) mi = min(mi, solve(x - 1, y));
                }

                if(x + 1 < n){
                    if(grid[x + 1][y] != grid[x][y]) { dist[x][y] = 0; bfs.push({x , y}); vis[x][y] = 1;}
                    //if(vis[x + 1][y] == 0) mi = min(mi, solve(x + 1, y));
                }

                if(y - 1 >= 0){
                    if(grid[x][y - 1] != grid[x][y]) { dist[x][y] = 0; bfs.push({x , y}); vis[x][y] = 1;}
                    //if(vis[x][y - 1] == 0) mi = min(mi, solve(x, y - 1));
                }

                if(y + 1 < m){
                    if(grid[x][y + 1] != grid[x][y]) { dist[x][y] = 0; bfs.push({x, y}); vis[x][y] = 1;}
                    //if(vis[x][y + 1] == 0) mi = min(mi, solve(x, y + 1));
                }
            }
        }

        while(!bfs.empty()){
            auto z = bfs.front();
            bfs.pop();

            int x = z.first;
            int y = z.second;

            if(x - 1 >= 0){
                    if(grid[x - 1][y] == grid[x][y] && !vis[x - 1][y]) { dist[x - 1][y] = dist[x][y] + 1; bfs.push({x - 1, y}); vis[x - 1][y] = 1;}
                    //if(vis[x - 1][y] == 0) mi = min(mi, solve(x - 1, y));
                }

                if(x + 1 < n){
                    if(grid[x + 1][y] == grid[x][y] && !vis[x + 1][y]) { dist[x + 1][y] = dist[x][y] + 1; bfs.push({x + 1, y}); vis[x + 1][y] = 1;}
                    //if(vis[x + 1][y] == 0) mi = min(mi, solve(x + 1, y));
                }

                if(y - 1 >= 0){
                    if(grid[x][y - 1] == grid[x][y] && !vis[x][y - 1]) { dist[x][y - 1] = dist[x][y] + 1; bfs.push({x , y - 1}); vis[x][y - 1] = 1;}
                    //if(vis[x][y - 1] == 0) mi = min(mi, solve(x, y - 1));
                }

                if(y + 1 < m){
                    if(grid[x][y + 1] == grid[x][y] && !vis[x][y + 1]) { dist[x][y + 1] = dist[x][y] + 1; bfs.push({x , y + 1}); vis[x][y + 1] = 1;}
                    //if(vis[x][y - 1] == 0) mi = min(mi, solve(x, y - 1));
                }
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                //cout << dist[i][j] << " ";
            }

            //cout << endl;
        }

        for(int i = 0; i<t; i++){
            long long x, y, p;
            cin >> x >> y >> p;

            int dd = min(p, (long long)dist[x - 1][y - 1]);

            int kencr = (grid[x - 1][y - 1]) ^ ((p - dd) % 2) ^ ((x + y) % 2);
            cout << kencr << endl;
        }
    }

    else if(m > 1 || n > 1){
        for(int i = 0; i<t; i++){
            long long x, y, p;
            cin >> x >> y >> p;

            //int dd = min(p, (long long)dist[x - 1][y - 1]);

            int kencr = (grid[x - 1][y - 1])  ^ ((x + y) % 2);
            cout << kencr << endl;
        }
    }

    else{
        for(int i = 0; i<t; i++){
            long long x, y, p;
            cin >> x >> y >> p;

            //int dd = min(p, (long long)dist[x - 1][y - 1]);

            int kencr = (grid[x - 1][y - 1]) ^ ((x + y) % 2);
            cout << kencr << endl;
        }
    }




}