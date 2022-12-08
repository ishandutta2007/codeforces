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

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
//#define cin fin
//#define cout fout

int n;
int arr[1010];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int res = min(arr[0], arr[n - 1]);
    for(int i = 1; i < n; i++)
        res = min(res, max(arr[i - 1], arr[i]));
    cout << res << endl;
    return 0;
}