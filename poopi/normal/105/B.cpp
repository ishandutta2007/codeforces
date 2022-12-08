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

int n, k, A;
int b[10], l[10];
double mx = 0;

void setMax(){
    double res = 0;
    for(int i = 0; i < 1 << n; i++){
        int cnt = 0, sum = 0;
        double p = 1;
        for(int j = 0; j < n; j++){
            if(i & 1 << j){
                cnt++;
                p *= l[j] / 100.;
            }
            else{
                sum += b[j];
                p *= 1. - l[j] / 100.;
            }
        }
        if(cnt * 2 > n)
            res += p;
        else res += p * A / (A + sum);
    }
    mx = max(mx, res);
}

void bt(int idx, int rem){
    if(idx == n){
        setMax();
        return;
    }
    int ini = l[idx];
    for(int i = 0; i <= rem; i++){
        bt(idx + 1, rem - i);
        l[idx] = min(100, l[idx] + 10);
    }
    l[idx] = ini;
}

int main(){
    cin >> n >> k >> A;
    for(int i = 0; i < n; i++)
        cin >> b[i] >> l[i];
    bt(0, k);
    cout << setprecision(8) << fixed << showpoint << mx << endl;
    return 0;
}