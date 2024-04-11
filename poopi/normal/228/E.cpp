                                        /* in the name of Allah */
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

#define VAR(X) (X << 1)
#define NOT(X) (X ^ 1)
#define CVAR(X,Y) (VAR(X) | (Y))
#define COL(X) (X & 1)
#define NVAR 200

int n, m;
vector<int> v[2 * NVAR];
int color[2 * NVAR];
int bc[2 * NVAR];

bool dfs( int a, int col ) {
    color[a] = col;
    int num = CVAR( a, col );
    for( int i = 0; i < v[num].size(); i++ ) {
        int adj = v[num][i] >> 1;
        int ncol = NOT( COL( v[num][i] ) );
        if( ( color[adj] == -1 && !dfs( adj, ncol ) ) || 
            ( color[adj] != -1 && color[adj] != ncol ) ) {
            color[a] = -1;
            return false;
        }
    }
    return true;
}

bool twosat() {
    memset( color, -1, sizeof color );
    for( int i = 0; i < n; i++ ){
        if( color[i] == -1 ){
            memcpy(bc, color, sizeof color);
            if( !dfs( i, 0 )){
                memcpy(color, bc, sizeof color);
                if(!dfs( i, 1 ))
                    return false;
            }
        }
    }
    return true;
}

int main(){
    cin >> n >> m;
    int a, b, c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        a--, b--;
        if(c == 1){
            v[VAR(a)].push_back(NOT(VAR(b)));
            v[NOT(VAR(b))].push_back(VAR(a));
            v[VAR(b)].push_back(NOT(VAR(a)));
            v[NOT(VAR(a))].push_back(VAR(b));
        }
        else{
            v[VAR(a)].push_back(VAR(b));
            v[VAR(b)].push_back(VAR(a));
            v[NOT(VAR(a))].push_back(NOT(VAR(b)));
            v[NOT(VAR(b))].push_back(NOT(VAR(a)));
        }
    }
    if(twosat()){
        int cnt = 0;
        for(int i = 0; i < n; i++)
            if(color[i] == 1)
                cnt++;
        cout << cnt << endl;
        for(int i = 0; i < n; i++)
            if(color[i] == 1)
                cout << i + 1 << ' ';
        cout << endl;
    }
    else cout << "Impossible" << endl;
    return 0;
}