                /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int r, c;
char ch[51][51];

int main(){
    cin >> r >> c;
    int mnr = r, mnc = c, mxr = 0, mxc = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> ch[i][j];
            if(ch[i][j] == '*'){
                mnr = min(mnr, i);
                mnc = min(mnc, j);
                mxr = max(mxr, i);
                mxc = max(mxc, j);
            }
        }
    }
    for(int i = mnr; i <= mxr; i++){
        for(int j = mnc; j <= mxc; j++)
            cout << ch[i][j];
        cout << endl;
    }
    return 0;
}