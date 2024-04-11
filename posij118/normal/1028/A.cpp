#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, row, col, num;
    row = 0;
    col = 0;
    char c;
    num = 0;
    cin >> n >> m;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> c;
            if(c == 'B'){
                num++;
                row+=i;
                col+=j;
            }
        }
    }

    cout << row/num + 1 << " " << col/num + 1;

}