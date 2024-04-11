#include <cstdio>
#include <vector>

using namespace std;

const int N = 110;
const int TIME = 12;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int nebo[N][N][12],star[N][N];
vector < int > un[N][N];
int n,c,x,y,q,s,x2,y2,t;

int main(){
    scanf("%d%d%d",&n,&q,&c);
    for(int i = 0;i<n;i++){
        scanf("%d%d%d",&x,&y,&s);
        un[x][y].push_back(s);
    }
    for(int i = 0;i<=c+1;i++){
        for(int j = 0;j<N-5;j++){
            for(int k = 0;k<N-5;k++){
                for(int u = 0;u<un[j][k].size();u++){
                    nebo[j][k][i] += (un[j][k][u] + i) % (c+1);
                }
            }
        }
    }
    for(int i = 0;i<=c+1;i++){
        for(int j = 0;j<N-5;j++){
            int c = 0;
            for(int k = 0;k<N-5;k++){
                c += nebo[j][k][i];
                nebo[j][k][i] = c;
                if(j)
                    nebo[j][k][i] += nebo[j-1][k][i];
            }
        }
    }
    for(int i = 0;i<q;i++){
        scanf("%d%d%d%d%d",&t,&x,&y,&x2,&y2);
        t %= (c+1);
        int sol = nebo[x2][y2][t] - nebo[x-1][y2][t] - nebo[x2][y-1][t] + nebo[x-1][y-1][t];
        printf("%d\n",sol);
    }
}