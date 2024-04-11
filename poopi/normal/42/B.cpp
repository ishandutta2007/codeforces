                                /* in the name of Allah */
#include <iostream>
#include <string>
using namespace std;

bool mark[10][10];
bool pc[10][10];
string st[5];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isin(int x, int y){
     return x >= 0 && x < 8 && y >= 0 && y < 8;     
}

int main(){
    for(int i = 0; i < 4; i++){
            cin >> st[i];
            int a = st[i][0] - 'a';
            int b = st[i][1] - '1';
            if(i < 3)
            pc[a][b] = true;
    }
    for(int i = 0; i < 2; i++){
            int a = st[i][0] - 'a';
            int b = st[i][1] - '1';            
            for(int d = 0; d < 4; d++){
                    for(int len = 1; len <= 8; len++){
                            int nx = a + len * dir[d][0];
                            int ny = b + len * dir[d][1];
                            if(!isin(nx, ny)) continue;
                            mark[nx][ny] = true;
                            if(pc[nx][ny]) break; 
                    }
            }
    }
    int a = st[2][0] - 'a';
    int b = st[2][1] - '1'; 
    for(int i = -1; i < 2; i++){
            for(int j = -1; j < 2; j++){
                    int nx = a + i;
                    int ny = b + j;
                    if(isin(nx, ny)){
                                mark[nx][ny] = true;
                    }
            }        
    }
    bool can = false;
    a = st[3][0] - 'a';
    b = st[3][1] - '1'; 
    for(int i = -1; i < 2; i++){
            for(int j = -1; j < 2; j++){
                    int nx = a + i;
                    int ny = b + j;
                    if(isin(nx, ny) && !mark[nx][ny])
                                can = true;
            }        
    }
    cout << (can ? "OTHER" : "CHECKMATE") << endl;
    return 0;
}