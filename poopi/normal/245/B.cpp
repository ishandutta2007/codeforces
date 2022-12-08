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

int x, y;

int main(){
    string str;
    cin >> str;
    if(str[0] == 'h'){
        cout << str.substr(0, 4) << "://" << str[4];
        str = str.substr(5);
    }
    else{
        cout << str.substr(0, 3) << "://" << str[3];
        str = str.substr(4);
    }
    for(int i = 0; i < str.length(); i++){
        if(str[i] == 'r' && str[i + 1] == 'u'){
            cout << ".ru";
            str = str.substr(i + 2);
            break;
        }
        cout << str[i];
    }
    if(str.length())
        cout << '/' << str;
    cout << endl;
    return 0;
}