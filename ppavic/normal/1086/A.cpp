#include <cstdio>
#include <cstdlib>

using namespace std;

const int N = 1005;

int Ax, Ay, Bx, By, Cx, Cy;
int mat[N][N];

void connect(int x1,int y1,int x2,int y2){
    int rl = x2;
    if(x1 > x2) x1 ^= x2, x2 ^= x1, x1 ^= x2, rl = x1;
    for(int z = x1;z<=x2;z++)
        mat[z][y1] = 1;
    if(y1 > y2) y1 ^= y2, y2 ^= y1, y1 ^= y2;
    for(int z = y1;z<=y2;z++)
        mat[rl][z] = 1;
}

int dis(int x1,int y1,int x2,int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}



int main(){
    scanf("%d%d%d%d%d%d", &Ax, &Ay, &Bx, &By, &Cx, &Cy);
    int bx = 0, by = 0;
    for(int i = 0;i<=1000;i++){
        for(int j = 0;j<=1000;j++){
            if(dis(Ax, Ay, bx, by) + dis(Bx, By, bx, by) + dis(Cx, Cy, bx, by) >= dis(Ax, Ay, i, j) + dis(Bx, By, i, j) + dis(Cx, Cy, i, j))
                bx = i, by = j;
        }
    }
    connect(Ax, Ay, bx, by);
    connect(Bx, By, bx, by);
    connect(Cx, Cy, bx, by);
    int cnt = 0;
    for(int i = 0;i<N;i++)
        for(int j = 0;j<N;j++)
            cnt += mat[i][j];
    printf("%d\n", cnt);
    for(int i = 0;i<N;i++)
        for(int j = 0;j<N;j++)
            if(mat[i][j]) printf("%d %d\n", i, j);
}