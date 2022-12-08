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

int n, mx;
vector <P> v;

int main(){
    int num, lev;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        lev = 1;
        while(!v.empty() && v.back().first < num){
            lev = v.back().second + 1;
            v.pop_back();
        }
        if(v.size() > 1 && v.back().second == lev)
            v.pop_back();
        if(!v.empty())
            mx = max(mx, lev);
        v.push_back(P(num, lev));
    }
    cout << mx << endl;
    return 0;
}