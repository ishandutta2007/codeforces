#include "bits/stdc++.h"

using namespace std;

const int N = 3e5 + 1;
const long long mod = 4444280714420857LL;
set < long long > ha;
int n , q;
char str[N + N];
long long pwr[N + N];
int strl = 0;
long long code(){
    long long res = 0;
    int i;
    for(i = 0 ; str[i] != '\0' ; ++i){
        res += res;
        if(res >= mod){
            res -= mod;
        }
        res += res;
        if(res >= mod){
            res -= mod;
        }
        res += str[i] - 'a' + 1;
        if(res >= mod){
            res -= mod;
        }
    }
    strl = i;
    return res;
}
void gen(){
    long long has = code();
    for(int i = 0 ; i < strl ; ++i){
        long long temp =  str[i] - 'a' + 1;
        temp *= pwr[strl - i - 1];
        temp %= mod;
        has -= temp;
        if(has < 0){
            has += mod;
        }
        for(int j = 0 ; j < 3 ; ++j){
            if(j != str[i] - 'a'){
                long long tem = pwr[strl - i - 1];
                tem *= j + 1;
                tem %= mod;
                ha.insert((has + tem)%mod);
            }
        }
        has += temp;
        if(has >= mod){
            has -= mod;
        }
    }
}
int main(){
    pwr[0] = 1;
    for(int i = 1 ; i < N + N ; ++i){
        pwr[i] = pwr[i-1] + pwr[i-1];
        if(pwr[i] >= mod){
            pwr[i] -= mod;
        }
        pwr[i] += pwr[i];
        if(pwr[i] >= mod){
            pwr[i] -= mod;
        }
    }
    cin >> n >> q;
    for(int i = 1 ; i <= n ; ++i){
        scanf("%s" , str);
        gen();
    }
    while(q--){
        scanf("%s" , str);
        if(ha.find(code()) == ha.end()){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
}