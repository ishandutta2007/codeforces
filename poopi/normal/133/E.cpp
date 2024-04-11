                                        /* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>
#define Inf 1000000

int n, k;
string str;
P dp[110][60];
bool mark[110][60];

P mem(int idx, int rem){
    if(idx == n)
        return (rem % 2 ? P(-Inf, -Inf) : P(0, 0));
    if(mark[idx][rem])
        return dp[idx][rem];
    mark[idx][rem] = true;
    P& ref = dp[idx][rem];
    ref = P(-Inf, -Inf);
    P t1 = mem(idx + 1, rem);
    if(t1.first != -Inf){
        if(str[idx] == 'T')
            swap(t1.first, t1.second);
        else{
            t1.first += 1;
            t1.second -= 1;
        }
        ref = t1;
    }
    if(rem > 0){
        P t2 = mem(idx + 1, rem - 1);
        if(t2.first != -Inf){
            if(str[idx] == 'F')
                swap(t2.first, t2.second);
            else{
                t2.first += 1;
                t2.second -= 1;
            }
            if(ref.first < t2.first)
                ref.first = t2.first;
            if(ref.second < t2.second)
                ref.second = t2.second;
        }
    }
    return ref;
}

int main(){
    while(cin >> str){
        n = str.length();
        memset(mark, false, sizeof mark);
        cin >> k;
        P res = mem(0, k);
        cout << max(res.first, res.second) << endl;
    }
    return 0;
}