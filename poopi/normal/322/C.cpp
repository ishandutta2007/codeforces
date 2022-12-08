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
#define PLL pair<int64, int64>

int a, b;
char ch[4] = {'U', 'D', 'L', 'R'};
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int getId(char c){
    for(int i = 0; i < 4; i++)
        if(ch[i] == c)
            return i;
    return -1;
}

int main(){
    int r = 0, c = 0;
    string str;
    cin >> a >> b >> str;
    for(int i = 0; i < str.length(); i++){
        r += dir[getId(str[i])][0];
        c += dir[getId(str[i])][1];
    }
    int x = 0, y = 0;
    str += 'D';
    string res = "No";
    for(int i = 0; i < str.length(); i++){
        int dx = (a - x);
        int dy = (b - y);
        int c1, c2;
        if(!((r == 0 && dx != 0) || (r != 0 && (dx % r || dx / r < 0))))
            if(!((c == 0 && dy != 0) || (c != 0 && (dy % c || dy / c < 0))))
                if(r == 0 || c == 0 || dx / r == dy / c)
                    res = "Yes";
        x += dir[getId(str[i])][0];
        y += dir[getId(str[i])][1];
    }
    cout << res << endl;
    return 0;
}