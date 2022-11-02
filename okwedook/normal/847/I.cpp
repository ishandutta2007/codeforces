#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
using namespace std;
int n,m,i,j,q,p,s[250][250],ANS;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
queue<int> qx,qy,ax,ay;
char a[250][250];
int d[250][250];
void bfs(int sx,int sy){
    int i,j,x,y,x1,y1;
    while(!qx.empty()) qx.pop();
    while(!qy.empty()) qy.pop();
    qx.push(sx); qy.push(sy);
    d[sx][sy] = (a[sx][sy] - 'A' + 1)*q;
    while(!qx.empty()){
        x = qx.front();
        y = qy.front();
        qx.pop(); qy.pop();
        ax.push(x); ay.push(y);
        if(d[x][y] <= 1) continue;
        for(i=0; i<4; i++){
            x1 = x + dx[i];
            y1 = y + dy[i];
            if(x1 >= 0 && y1 >= 0 && x1 < n && y1 < m){
                if(!d[x1][y1] && a[x1][y1] != '*'){
                    d[x1][y1] = d[x][y]/2;
                    //cout << x1 << " " << y1 << " " << a[x1][y1] << " " << s[x1][y1] << endl;
                    qx.push(x1); qy.push(y1);
                }
            }
        }
    }
    while(!ax.empty()){
        s[ax.front()][ay.front()] +=  d[ax.front()][ay.front()];
        d[ax.front()][ay.front()] = 0;
        ax.pop(); ay.pop();
    }
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q >> p;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(a[i][j] != '*' && a[i][j] != '.')
                bfs(i, j);
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(s[i][j] > p) ANS++;
        }
    }
    cout << ANS;
    return 0;
}