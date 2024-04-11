#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

int X,Y,cnt;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
bool edge[110][110][4];
bool used[110][110];

void dfs(int x, int y){
    int i;
    if(x < 0 || x >= X || y < 0 || y >= Y || used[x][y]) return;
    used[x][y] = true; cnt++;
    for(int i=0;i<4;i++) if(!edge[x][y][i]) dfs(x+dx[i],y+dy[i]);
}

int main(void){
    int N,x1,y1,x2,y2,i,j;
    
    cin >> X >> Y >> N;
    for(int i=0;i<N;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2) for(j=y1;j<y2;j++) edge[x1-1][j][0] = edge[x1][j][1] = true;
        if(y1 == y2) for(j=x1;j<x2;j++) edge[j][y1-1][2] = edge[j][y1][3] = true;
    }
    
    vector <int> ans;
    for(int i=0;i<X;i++)for(int j=0;j<Y;j++)if(!used[i][j]){
        cnt = 0;
        dfs(i,j);
        ans.push_back(cnt);
    }
    
    sort(ans.begin(),ans.end());
    for(int i=0;i<=N;i++){
        cout << ans[i];
        if(i == N) cout << endl; else cout << ' ';
    }
    
    return 0;
}