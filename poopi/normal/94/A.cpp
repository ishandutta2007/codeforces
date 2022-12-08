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
    string s[10];
    cin >> str;
    for(int i = 0; i < 10; i++)
        cin >> s[i];
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 10; j++)
            if(str.substr(0, 10) == s[j])
                cout << j;
        str = str.substr(10);
    }
    cout << endl;
    return 0;
}