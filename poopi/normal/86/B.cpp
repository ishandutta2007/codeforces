#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define P pair<int, int>

int r, c;
char mat[1010][1010];
bool mark[1010][1010];
int ref[1010][1010];
vector <P> col[1000010];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool ispos(int x, int y){
        return x >= 0 && x < r && y >= 0 && y < c && mat[x][y] != '#';
}

int main(){
        while(cin >> r >> c){
                memset(mark, false, sizeof mark);
                for(int i = 0; i < r * c; i++)
                        if(!col[i].empty())
                                col[i].clear();
                for(int i = 0; i < r; i++)
                        scanf("%s", mat[i]);
                int cnt = 0;
                for(int i = 0; i < r; i++){
                        for(int j = 0; j < c; j++){
                                if(mat[i][j] == '#' || mark[i][j])
                                        continue;
                                if(j + 1 < c && mat[i][j + 1] != '#' && !mark[i][j + 1]){
                                        mark[i][j] = mark[i][j + 1] = true;
                                        col[cnt].push_back(P(i, j));
                                        col[cnt].push_back(P(i, j + 1));
                                        ref[i][j] = ref[i][j + 1] = cnt++;
                                }
                                else if(i + 1 < r && mat[i + 1][j] != '#' && !mark[i + 1][j]){
                                        mark[i][j] = mark[i + 1][j] = true;
                                        col[cnt].push_back(P(i, j));
                                        col[cnt].push_back(P(i + 1, j));
                                        ref[i][j] = ref[i + 1][j] = cnt++;
                                }
                        }
                }
                for(int i = 0; i < r; i++){
                        for(int j = 0; j < c; j++){
                                if(mat[i][j] != '#' && !mark[i][j]){
                                        if(i > 0 && mark[i - 1][j]){
                                                ref[i][j] = ref[i - 1][j];
                                                col[ref[i][j]].push_back(P(i, j));
                                                mark[i][j] = true;
                                        }
                                        else if(j > 0 && mark[i][j - 1]){
                                                ref[i][j] = ref[i][j - 1];
                                                col[ref[i][j]].push_back(P(i, j));
                                                mark[i][j] = true;
                                        }
                                        else if(j + 1 < c && mark[i][j + 1]){
                                                ref[i][j] = ref[i][j + 1];
                                                col[ref[i][j]].push_back(P(i, j));
                                                mark[i][j] = true;
                                        }
                                }
                        }
                }
                bool fl = true;
                for(int i = 0; i < r; i++)
                        for(int j = 0; j < c; j++)
                                if(mat[i][j] != '#' && !mark[i][j])
                                        fl = false;
                if(!fl)
                        cout << -1 << endl;
                else{
                        bool mark[10];
                        for(int i = 0; i < cnt; i++){
                                //cout << "COL " << i << endl;
                                for(int k = 0; k < 10; k++)
                                        mark[k] = 0;
                                int sz = col[i].size();
                                for(int j = 0; j < sz; j++){
                                        int x = col[i][j].first;
                                        int y = col[i][j].second;
                                        //cout << x << ' ' << y << endl;
                                        for(int k = 0; k < 4; k++){
                                                int nx = x + dir[k][0];
                                                int ny = y + dir[k][1];
                                                //cout << "Y " << nx << ' ' << ny << endl;
                                                if(ispos(nx, ny) && ref[nx][ny] != ref[x][y] && mat[nx][ny] != '.'){
                                                        mark[mat[nx][ny] - '0'] = true;
                                                        //cout << "S " << nx << ' ' << ny << endl;
                                                }
                                        }
                                }
                                for(int k = 0; k < 10; k++){
                                        if(!mark[k]){
                                                //cout << k << endl;
                                                int sz = col[i].size();
                                                for(int j = 0; j < sz; j++){
                                                        int x = col[i][j].first;
                                                        int y = col[i][j].second;
                                                        mat[x][y] = (char)('0' + k);
                                                }
                                                break;
                                        }
                                }
                                /*for(int i = 0; i < r; i++){
                                        for(int j = 0; j < c; j++)
                                                cout << mat[i][j];
                                        cout << endl;
                                }*/
                        }
                        for(int i = 0; i < r; i++){
                                for(int j = 0; j < c; j++)
                                        cout << mat[i][j];
                                cout << endl;
                        }
                }
        }
        return 0;
}