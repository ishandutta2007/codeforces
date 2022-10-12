#include<bits/stdc++.h>
using namespace std;

int a[102][102], b[102][102], c[102][102];
int n,m;

int main(){
    cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> b[i][j];
        }
    }
    memset(a,0,sizeof(a));
    memset(c,0,sizeof(c));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (b[i][j] == 1){
                bool bisa = true;
                for (int k=0; k<m; k++) if (b[i][k] == 0) {bisa = false; break;}
                for (int k=0; k<n; k++) if (b[k][j] == 0) {bisa = false; break;}
                if (bisa){
                    a[i][j] = 1;
                    for (int k=0; k<m; k++) {c[i][k] = 1;}
                    for (int k=0; k<n; k++) {c[k][j] = 1;}
                }
            }
        }
    }
    bool bisa = true;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (b[i][j] != c[i][j]) {bisa = false; break;}
    if (bisa){
        cout << "YES" << endl;
        for (int i=0; i<n; i++){
            for (int j=0; j<m-1; j++) cout << a[i][j] << " ";
            cout << a[i][m-1] << endl;
        }
    }
    else cout << "NO" << endl;

    return 0;
}