#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <complex>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define x first
#define y second
#define pb push_back

using namespace std;

typedef long long LL;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int n, m, k;
bool V[510][510];
char M[510][510];

bool in(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int x, int y){
    V[x][y] = 1;
    int nx, ny;
    FWD(d,0,4){
        nx = x + dx[d];
        ny = y + dy[d];
        if(in(nx, ny) && !V[nx][ny] && M[nx][ny] == '.')
            dfs(nx, ny);
    }
    if(k){
        M[x][y] = 'X';
        --k;
    }
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    FWD(i,0,n) scanf("%s", M[i]);
    FWD(i,0,n)
        FWD(j,0,m)
            if(M[i][j] == '.'){
                dfs(i, j);
                FWD(r,0,n)
                    printf("%s\n", M[r]);
                return 0;
            }
    return 0;
}