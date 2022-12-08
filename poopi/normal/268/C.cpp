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

ifstream fin("input.txt");
ofstream fout("output.txt");

//#define cin fin
//#define cout fout
#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define PLL pair<int64, int64>

int n, m;

int main(){
    cin >> n >> m;
    cout << min(n, m) + 1 << endl;
    for(int i = 0; i <= min(n, m); i++)
        cout << i << ' ' << m - i << endl;
    return 0;
}