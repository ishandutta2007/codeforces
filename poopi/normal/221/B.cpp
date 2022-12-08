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

int n, k;
int arr[100010];
bool mark[10];

bool ok(int num){
    while(num){
        if(mark[num % 10])
            return true;
        num /= 10;
    }
    return false;
}

int main(){
    cin >> n;
    int t = n;
    while(t){
        mark[t % 10] = true;
        t /= 10;
    }
    int cnt = 0;
    for(int i = 1; i * i <= n; i++){
        if(n % i) continue;
        if(ok(i)) cnt++;
        if(n / i != i && ok(n / i)) cnt++;
    }
    cout << cnt << endl;
    return 0;
}