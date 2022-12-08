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
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

int main(){
    string str;
    cin >> str;
    int res, cnt = 0;
    for(int i = 0; i < str.length(); i++)
        if(str[i] >= 'A' && str[i] <= 'Z')
            cnt++;
    res = cnt;
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z')
            cnt--;
        else cnt++;
        res = min(cnt, res);
    }
    cout << res << endl;
    return 0;
}