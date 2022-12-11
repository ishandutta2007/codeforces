#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e12

void open(){
    freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}

main(){
    //open();
    //ini();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    int l[n][m];
    for(int j = 0;j<n;j++){
        for(int i = 0;i<m;i++){
            cin >> l[j][i];
        }
    }
    int colT = 0,col = 0;
    int tekM = 0,tek = 0;
    int ansS = 0;
    int movS = 0;
    int p;
    for(int j = 0;j<m;j++){
        tekM = 0,tek = 0;
        col = 0;
        for(int i = 0;i<n;i++){
            if(l[i][j] == 1){
                colT = 0;
                p = k;
                for(int x = i;x<n && p>0;x++){
                    colT += l[x][j];
                    p--;
                }
                if(colT > tekM || (colT == tekM && tek>col)){
                    tek = col;
                    tekM = colT;
                }
                col++;
            }
        }
        ansS +=tek;
        movS += tekM;
    }
    cout << movS << " " << ansS;
    return 0;
}