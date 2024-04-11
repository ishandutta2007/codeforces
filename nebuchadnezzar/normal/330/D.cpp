#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

struct cell{
    int x, y, l;
};

int r, c, masn[1000][1000], mast[1000][1000], bx, by, ex, ey, masl[1000][1000];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

bool used[1000][1000];

queue <cell> q;

cell pos, bpos, npos, epos;

string s;

int main(){
    cin >> r >> c;

    for(int i = 0; i < r; ++i){
        cin >> s;
        for(int j = 0; j < c; ++j){
            if(s[j] == 'T'){
//                masn[i][j] = 0;
                mast[i][j] = 1;
            }
            else if(s[j] == 'S'){
                bpos.x = i;
                bpos.y = j;
            }
            else if(s[j] == 'E'){
                epos.x = i;
                epos.y = j;
            }
            else{
                masn[i][j] = int(s[j]) - int('0');
                //cout << i << " " << j << " " << masn[i][j] << endl;    
            }
        }
    }

    //cout << "end of read\n";
   

    q.push(epos);
    //cout << r << " " << c << endl;
    used[epos.x][epos.y] = true;

    while(q.size() > 0){
        //cout << q.size() << endl;
        pos = q.front();
        q.pop();
        //cout << pos.x << " " << pos.y << " " << pos.l << endl;
        //cout << pos.x << " " << pos.y << endl;
        
        masl[pos.x][pos.y] = pos.l;
        for(int i = 0; i < 4; ++i){
            npos = pos;
            npos.x += dx[i];
            npos.y += dy[i];
            npos.l = pos.l + 1;


            if(npos.x >= 0 && npos.x < r && npos.y >= 0 && npos.y < c && mast[npos.x][npos.y] == 0 && not used[npos.x][npos.y]){
                q.push(npos);
                used[npos.x][npos.y] = true;
                
            }
        } 
    }
    //cout << "end of bfs\n";
    //cout << masl[0][6] << endl;
    int ans = 0;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            if(masn[i][j] > 0){
                //cout << (masl[i][j] <= masl[bx][by]) << " " << used[i][j] << endl;
                if(masl[i][j] <= masl[bpos.x][bpos.y] && used[i][j] == true){
                    ans += masn[i][j];
                    //cout << i << " " << j << endl;
                }
            }
        }
    }
    //cout << "end of counting\n";

    cout << ans;

    return 0;
}