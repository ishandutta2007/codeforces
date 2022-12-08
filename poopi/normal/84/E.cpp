                                /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
using namespace std;

#define P pair<int, int>

struct triple{
    int val, r, c, par;
    triple(int _v, int _r, int _c, int _p){
        val = _v, r = _r, c = _c, par = _p;
    }
    bool operator < (const triple &a) const{
        return val > a.val;
    }
};

int n, m, k, len;
int rs, cs, re, ce;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char mat[60][60];
bool mark[60][60];
int dist[60][60];
int par[60][60];
bool ok[30];
string res;
priority_queue <triple> q[2];

string bfs(){
    for(int i = 0; i < 2; i++)
        while(!q[i].empty())
            q[i].pop();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mark[i][j] = false;
            dist[i][j] = -1;
            par[i][j] = -1;
        }
    }
    dist[rs][cs] = 0;
    int cur = 0, bef = 1, prev, cnt;
    q[cur].push(triple(1, rs, cs, -1));
    while(!q[0].empty() || !q[1].empty()){
        if(q[bef].empty()){
            bef = 1 - bef;
            cur = 1 - cur;
            prev = cnt = 0;
        }
        triple t = q[bef].top();
        q[bef].pop();
        int r = t.r;
        int c = t.c;
        int val = t.val;
        if(val > prev)
            cnt++;
        prev = val;
        if(par[r][c] != -1)
            continue;
        par[r][c] = t.par;
        if(r == re && c == ce)
            break;
        for(int i = 0; i < 4; i++){
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            //cout << nr << ' ' << nc << ' ' << dist[nr][nr] << ' ' << ok[mat[nr][nc]] << endl;
            if((nr == re && nc == ce) || (nr >= 0 && nr < n && nc >= 0 && nc < m && ok[mat[nr][nc] - 'a'])){
                if(dist[nr][nc] == -1 || dist[nr][nc] == dist[r][c] + 1){
                    dist[nr][nc] = dist[r][c] + 1;
                    int nval = cnt * 30 + mat[nr][nc] - 'a';
                    q[cur].push(triple(nval, nr, nc, i));
                }
            }
        }
    }
    if(par[re][ce] == -1)
        return "";
    string res;
    int x = re, y = ce;
    while(x != rs || y != cs){
        res = mat[x][y] + res;
        int p = par[x][y];
        x -= dir[p][0];
        y -= dir[p][1];
        //cout << x << '  '<< y << endl;
    }
    return res;
}

void bt(int str, int rem){
    if(rem == 0){
        string tmp = bfs();
        if(tmp.length() < 1)
            return;
        tmp = tmp.substr(0, (int)tmp.length() - 1);
        if(len == -1 || tmp.length() < len || (tmp.length() == len && tmp < res)){
            len = tmp.length();
            res = tmp;
        }
    }
    else{
        for(int i = str; i < 26; i++){
            ok[i] = true;
            bt(i + 1, rem - 1);
            ok[i] = false;
        }
    }
}

int main(){
    while(cin >> n >> m >> k){
        len = -1;
        res = "";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> mat[i][j];
                if(mat[i][j] == 'S')
                    rs = i, cs = j;
                if(mat[i][j] == 'T')
                    re = i, ce = j;
            }
        }
        bt(0, k);
        if(len == -1)
            cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}