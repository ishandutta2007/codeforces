#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second

int main(){

    int n,m;
    cin >> n >> m;
    int col[n+2][m+2];
    int bf[n+2][m+2];
    for(int i = 0;i<=n+1;i++){
        for(int x = 0;x<=m+1;x++){
            col[i][x] = -1;
            bf[i][x] = -1;
        }
    }
    char s;
    for(int i = 1;i<=n;i++){
        for(int y = 1;y<=m;y++){
            cin >> s;
            col[i][y] = s-96;
            bf[i][y] = 1e9;
        }
    }
    bool cy = false;
    queue<pair<int,int> >wk;
    int c1,c2;
    for(int x = 1;x<=n;x++){
        for(int y = 1;y<=m;y++){
            if(bf[x][y] == 1e9){
                wk.push(mp(x,y));
                bf[x][y] = 0;
                while(wk.size()>0){
                    c1 = wk.front().fi;
                    c2 = wk.front().se;
                    if(bf[c1+1][c2] != -1 && col[c1+1][c2] == col[c1][c2]){
                        if(bf[c1+1][c2] == 1e9){
                            bf[c1+1][c2] = bf[c1][c2]+1;
                            wk.push(mp(c1+1,c2));
                        }
                        else{
                            if(bf[c1+1][c2] != bf[c1][c2]-1){
                                cy = true;
                            }
                        }
                    }
                    if(bf[c1-1][c2] != -1 && col[c1-1][c2] == col[c1][c2]){
                        if(bf[c1-1][c2] == 1e9){
                            bf[c1-1][c2] = bf[c1][c2]+1;
                            wk.push(mp(c1-1,c2));
                        }
                        else{
                            if(bf[c1-1][c2] != bf[c1][c2]-1){
                                cy = true;
                            }
                        }
                    }
                    if(bf[c1][c2-1]!=-1 && col[c1][c2-1] == col[c1][c2]){
                        if(bf[c1][c2-1] == 1e9){
                            bf[c1][c2-1] = bf[c1][c2]+1;
                            wk.push(mp(c1,c2-1));
                        }
                        else{
                            if(bf[c1][c2-1] != bf[c1][c2]-1){
                                cy = true;
                            }
                        }
                    }
                    if(bf[c1][c2+1]!=-1 && col[c1][c2+1] == col[c1][c2]){
                        if(bf[c1][c2+1] == 1e9){
                            bf[c1][c2+1] = bf[c1][c2]+1;
                            wk.push(mp(c1,c2+1));
                        }
                        else{
                            if(bf[c1][c2+1] != bf[c1][c2]-1){
                                cy = true;
                            }
                        }
                    }
                    wk.pop();
                }
            }
        }
    }
    if(cy==true)puts("Yes");
    else puts("No");
    return 0;
}