                                /* in the name of Allah */

#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, double>
#define Mod 1000000007LL
#define Inf 1000000

struct node{
    int c1, c2, sd;
    node(int _c1 = 0, int _c2 = 0, int _sd = 0){
        c1 = _c1, c2 = _c2, sd = _sd;
    }
};

int n, k, x, y;
int dis[60][60][2];
int64 c[60][60];
int64 cnt[60][60][2];
queue <node> q;

int64 calc(int c1, int c2, int sd){
    if(sd == 1 && c1 == x && c2 == y)
        return 1;
    if(cnt[c1][c2][sd] != -1)
        return cnt[c1][c2][sd];
    int64 &ref = cnt[c1][c2][sd];
    ref = 0;
    for(int i = 0; i <= c1; i++){
        for(int j = 0; j <= c2; j++){
            if(i + j != 0 && i * 50 + j * 100 <= k && dis[x - c1 + i][y - c2 + j][1 - sd] == dis[c1][c2][sd] - 1){
                int64 t1 = (c[i][c1] * c[j][c2]) % Mod;
                ref = (ref + t1 * calc(x - c1 + i, y - c2 + j, 1 - sd)) % Mod;
            }
        }
    }
    return ref;
}

int main(){
    c[0][0] = 1;
    for(int i = 1; i < 60; i++){
        c[0][i] = c[i][i] = 1;
        for(int j = 1; j < i; j++)
            c[j][i] = (c[j - 1][i - 1] + c[j][i - 1]) % Mod;
    }
    cin >> n >> k;
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        if(tmp == 50)
            x++;
        else y++;
    }
    memset(dis, -1, sizeof dis);
    q.push(node(x, y, 1));
    dis[x][y][1] = 0;
    while(!q.empty()){
        node tmp = q.front();
        q.pop();
        int c1 = tmp.c1, c2 = tmp.c2, sd = tmp.sd;
        for(int i = 0; i <= c1; i++){
            for(int j = 0; j <= c2; j++){
                if(i + j != 0 && i * 50 + j * 100 <= k){
                    int nc1 = x - c1 + i;
                    int nc2 = y - c2 + j;
                    if(dis[nc1][nc2][1 - sd] == -1){
                        dis[nc1][nc2][1 - sd] = dis[c1][c2][sd] + 1;
                        q.push(node(nc1, nc2, 1 - sd));
                    }
                }
            }
        }
    }
    memset(cnt, -1, sizeof cnt);
    cout << dis[x][y][0] << endl;
    cout << (dis[x][y][0] == -1 ? 0 : calc(x, y, 0)) << endl;
    return 0;
}