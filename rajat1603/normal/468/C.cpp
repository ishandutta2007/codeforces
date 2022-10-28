#include "bits/stdc++.h"
using namespace std;
const int LN = 19;
const int SN = LN * 9;
string str;
long long dp[LN][SN][2];
long long solve(int pos , int sum , bool p){
    if(pos >= str.size()){
        return sum;
    }
    if(dp[pos][sum][p] != -1){
        return dp[pos][sum][p];
    }
    long long res = 0;
    for(int i = 0 ; i < 10 ; ++i){
        if(!p && i > str[pos] - '0'){
            continue;
        }
        res += solve(pos + 1 , sum + i , p || (i < str[pos] - '0'));
    }
    return dp[pos][sum][p] = res;
}
long long solve(long long num){
    str = to_string(num);
    memset(dp , -1 , sizeof(dp));
    return solve(0 , 0 , 0);
}
const long long inf = 2e16;
const int MX = 1e6 + 6;
long long a;
long long who[MX];
int sum(long long num){
    int res = 0;
    while(num){
        res += num % 10;
        num /= 10;
    }
    return res;
}
int main(){
    cin >> a;
    long long l = 1;
    long long r = inf;
    while(l < r){
        long long mid = l + r >> 1;
        if(solve(mid) < a){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    long long curr = l;
    long long valr = solve(l);
    long long curl = 0;
    long long vall = 0;
    memset(who , -1 , sizeof(who));
    who[vall] = curl;
    while(curl < MX && curl + 1 < curr){
        ++curl;
        vall += sum(curl);
        vall %= a;
        if(vall < MX){
            if(who[vall] == -1){
                who[vall] = curl;
            }
        }
    }
    while(1){
        if(who[valr % a] != -1){
            printf("%lld %lld\n" , who[valr % a] + 1 , curr);
            return 0;
        }
        ++curr;
        valr += sum(curr);
        valr %= a;
        while(curl < MX && curl + 1 < curr){
            vall += sum(++curl);
            vall %= a;
            if(vall < MX){
                if(who[vall] == -1){
                    who[vall] = curl;
                }
            }
        }
    }
}