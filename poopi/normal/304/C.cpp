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
    cin >> n;
    if(n % 2){
        for(int i = 0, j = 0; i < n; i++, j = (j + n - 1) % n)
            cout << j << ' ';
        cout << endl;
        for(int i = 0, j = 0; i < n; i++, j = (j + 2) % n)
            cout << j << ' ';
        cout << endl;
        for(int i = 0; i < n; i++)
            cout << i << ' ';
        cout << endl;
    }
    else cout << -1 << endl;
    return 0;
}