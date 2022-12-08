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

int main(){
    int n;
    string str;
    cin >> n >> str;
    int l = -1, r = -1;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == 'L' && l == -1)
            l = i;
        if(str[i] == 'R')
            r = i;
    }
    if(l != -1)
        cout << l + 1 << ' ' << l << endl;
    else cout << r + 1 << ' ' << r + 2 << endl;
    return 0;
}