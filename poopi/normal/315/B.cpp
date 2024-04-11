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

int n, m, sum;
int arr[100010];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int t, a, b;
    for(int i = 0; i < m; i++){
        cin >> t >> a;
        if(t == 1){
            cin >> b;
            arr[a - 1] = b - sum;
        }
        if(t == 2)
            sum += a;
        if(t == 3)
            cout << arr[a - 1] + sum << endl;
    }
    return 0;
}