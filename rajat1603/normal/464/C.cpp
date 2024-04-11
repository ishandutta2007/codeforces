#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n;
char str[N];
int q , ans;
pair < int , int > val[10];
int dig[N];
string to[N];
char tmp[N];
int main(){
    scanf("%s" , str);
    scanf("%d" , &q);
    for(int i = 1 ; i <= q ; ++i){
        scanf("%d%c%c" , dig + i , &tmp[0] , &tmp[0]);
        gets(tmp);
        to[i] = tmp;
    }
    for(int i = 0 ; i < 10 ; ++i){
        val[i] = {i , 10};
    }
    for(int i = q ; i >= 1 ; --i){
        auto res = make_pair(0 , 1);
        for(char x : to[i]){
            res.first = (1LL * res.first * val[x - '0'].second + val[x - '0'].first) % mod;
            res.second = (1LL * res.second * val[x - '0'].second) % mod;
        }
        val[dig[i]] = res;
    }
    for(int i = 0 ; str[i] ; ++i){
        ans = (1LL * ans * val[str[i] - '0'].second + val[str[i] - '0'].first) % mod;
    }
    printf("%d\n" , ans);
}