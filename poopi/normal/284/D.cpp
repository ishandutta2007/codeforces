                        /* in the name of Allah */

#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>

int N;
int nex[200010];
int64 ini[200010];
int64 arr[200010];
int64 dp[200010];

int64 mem(int idx){
    if(idx == 0)
        return 0;
    if(dp[idx] != -1)
        return dp[idx];
    dp[idx] = -2;
    int64 tmp = mem(nex[idx]);
    if(tmp == -2)
        return dp[idx] = -2;
    return dp[idx] = tmp + arr[idx];
}

void setN(int i){
    int idx = i + ini[i];
    arr[i] = ini[i];
    if(idx < 1 || idx > N)
        nex[i] = 0;
    else{
        arr[i] += ini[idx];
        idx -= ini[idx];
        if(idx < 1 || idx > N)
            nex[i] = 0;
        else nex[i] = idx;
    }
}

int main(){
    memset(dp, -1, sizeof dp);
    cin >> N;
    for(int i = 2; i <= N; i++)
        cin >> ini[i];
    for(int i = 2; i <= N; i++)
        setN(i);
    for(int i = 1; i < N; i++){
        ini[1] = i;
        setN(1);
        dp[1] = -1;
        int64 t = mem(1);
        if(t == -2)
            cout << -1 << endl;
        else cout << t << endl;
    }
    return 0;
}