#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a,b;
    cin >> a >> b;
    int sec;
    cin >> sec;
    map<char,int> r;
    r['v'] = 0;
    r['<'] = 1;
    r['^'] = 2;
    r['>'] = 3;
    int dir = r[a];
    bool c1 = false,c2 = false;
    for(int i = 0;i<sec%4;i++){
        dir++;
        dir%=4;
    }
    if(r[b] == dir){
        c1 = true;
    }
    dir = r[a];
    for(int x = 0;x<sec%4;x++){
        if(dir == 0){
            dir = 3;
        }
        else{
            dir--;
        }
    }
    if(dir == r[b]){
        c2 = true;
    }
    if(c1 == true && c2 == true){
        cout << "undefined";
    }
    else if(c1 == true){
        cout << "cw";
    }
    else{
        cout << "ccw";
    }
    return 0;
}