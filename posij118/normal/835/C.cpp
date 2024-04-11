#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, c;
    cin >> n >> q >> c;

    int coord[n][3];
    for(int i=0; i<n; i++){
        cin >> coord[i][0] >> coord[i][1] >> coord[i][2];
    }

    vector<int> sky[101][101];
    for(int i=0; i<n; i++){
        sky[coord[i][0]][coord[i][1]].push_back(coord[i][2]);
    }

    int pref[101][101][c+1];
    for(int i=0; i<(c+1); i++){
        for(int j=0; j<101; j++){
            pref[0][j][i]=0;
            pref[j][0][i]=0;
        }

        for(int j=1; j<101; j++){
            for(int k=1; k<101; k++){
                pref[j][k][i]=pref[j][k-1][i]+pref[j-1][k][i]-pref[j-1][k-1][i];
                for(int l=0; l<sky[j][k].size(); l++){
                    pref[j][k][i]+=(i+sky[j][k][l])%(c+1);
                }
            }
        }
    }

    int que[q][5];

    for(int i=0; i<q; i++){
        for(int j=0; j<5; j++){
            cin >> que[i][j];
        }

        cout << pref[que[i][3]][que[i][4]][que[i][0]%(c+1)] + pref[que[i][1]-1][que[i][2]-1][que[i][0]%(c+1)] - pref[que[i][1]-1][que[i][4]][que[i][0]%(c+1)] - pref[que[i][3]][que[i][2]-1][que[i][0]%(c+1)] << endl;
    }

}