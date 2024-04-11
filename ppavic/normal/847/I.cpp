#include <cstdio>
#include <queue>
#include <map>

using namespace std;

typedef pair < int,int> pii;

struct pol{
    int x,y,s;
};

const int N = 300;

int n,m;
int px[4] = {1,-1,0,0};
int py[4] = {0,0,1,-1};
int noise[N][N];
int bio[N][N],p,q,sol;
char a[N][N];

vector < pii > clr;
queue < pol > qq;

void bfs(int x,int y,int k){
    clr.clear();
    pol nw;nw.x = x;nw.y = y;nw.s = k;
    noise[x][y] += k;
    qq.push(nw);
    bio[x][y] = 1;
    while(!qq.empty()){
        pol cur = qq.front();
        qq.pop();
        if(cur.s == 1) continue;
        for(int u = 0;u<4;u++){
            int nx = cur.x + px[u];
            int ny = cur.y + py[u];
            clr.push_back(make_pair(nx,ny));
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(a[nx][ny] == '*') continue;
            if(bio[nx][ny] == 1) continue;
            bio[nx][ny] = 1;
            pol nw;nw.x = nx;nw.y = ny;nw.s = cur.s / 2;
            if(noise[nx][ny] <= p)
                noise[nx][ny] += nw.s;
            qq.push(nw);
        }
    }
    bio[x][y] = 0;
    for(int i = 0;i<clr.size();i++)
        bio[clr[i].first][clr[i].second]--;
}

int main(){
    scanf("%d %d %d %d",&n,&m,&q,&p);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            scanf(" %c",&a[i][j]);
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(a[i][j] >= 'A' && a[i][j] <= 'Z'){
                int ci = (a[i][j]-'A' + 1) * q;
                bfs(i,j,ci);
            }

        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(noise[i][j] > p) sol++;
        }
    }
    printf("%d\n",sol);
}