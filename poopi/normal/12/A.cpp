                /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char ch[3][3];

int main(){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> ch[i][j];
    string res = "YES";
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(ch[i][j] == 'X' && ch[2-i][2-j] != 'X')
                res = "NO";
    cout << res << endl;
    return 0;
}