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
#define Max 1001000
#define Mod 1000000007LL

int cnt, ted;
bool npr[Max];
vector <int64> pr;

void findPrime(){
    for(int i = 2; i < Max; i++){
        if(!npr[i]){
            pr.push_back(i);
            for(int j = 2 * i; j < Max; j += i)
                npr[j] = true;
        }
    }
}

bool isPrime(int64 num){
    if(num < 2)
        return false;
    if(num < Max)
        return !npr[num];
    for(int i = 0; pr[i] * pr[i] <= num; i++)
        if(num % pr[i] == 0)
            return false;
    return true;
}

void bt(int64 n, int64 pnt){
    int64 val = pr[pnt];
    if(val * val > n){
        if(n == 1)
            cnt++;
        if(isPrime(n - 1) && n - 1 >= val)
            cnt++;
        return;
    }
    
    bt(n, pnt + 1);
    
    int64 p = val;
    while(p + 1 <= n){
        if(n % (p + 1) == 0)
            bt(n / (p + 1), pnt + 1);
        p *= val;
    }
}

int main(){
    findPrime();
    int64 n;
    cin >> n;
    bt(n, 0);
    cout << cnt << endl;
    return 0;
}