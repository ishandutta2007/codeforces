                /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int r, c;
char ch[110][110];

int main(){
    string res = "YES";
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> ch[i][j];
            if(i > 0 && ch[i][j] == ch[i-1][j])
                res = "NO";
            if(j > 0 && ch[i][j] != ch[i][j-1])
                res = "NO";
        }
    }
    cout << res << endl;
    return 0;
}