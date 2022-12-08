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
    string str;
    cin >> str;
    int t = ((str[0] - '0') * 10 + str[1] - '0') * 60 + (str[3] - '0') * 10 + str[4] - '0';
    int p = t;
    int a = 0, b = 0, c = 0, d = 1;
    while(a != d || b != c){
        p++;
        if(p == 1440)
            p = 0;
        a = p % 10;
        b = (p % 60) / 10;
        c = (p / 60) % 10;
        d = p / 600;
    }
    cout << a << b << ':' << c << d << endl;
    return 0;
}