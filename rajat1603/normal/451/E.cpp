#include "bits/stdc++.h"
using namespace std;
const int N = 22;
const int mod = 1e9 + 7;
int add(int a , int b){
    int res = a + b;
    if(res >= mod){
        return res - mod;
    }
    return res;
}
int mult(int a , int b){
    long long res = a;
    res *= b;
    if(res >= mod){
        return res % mod;
    }
    return res;
}
int power(int a , int b){
    int res = 1;
    while(b){
        if(b & 1){
            res = mult(res , a);
        }
        a = mult(a , a);
        b >>= 1;
    }
    return res;
}
int fact[N];
int ifact[N];
int n;
long long s;
int ans;
vector < pair < long long , int > > poly;
long long f;
void pre(){
    fact[0] = 1;
    for(int i = 1 ; i < N ; ++i){
        fact[i] = mult(fact[i - 1] , i);
    }
    ifact[N - 1] = power(fact[N - 1] , mod - 2);
    for(int i = N - 2 ; i >= 0 ; --i){
        ifact[i] = mult(ifact[i + 1] , i + 1);
    }
}
vector < pair < long long , int > > mult(vector < pair < long long , int > > a , vector < pair < long long , int > > b){
    vector < pair < long long , int > > res;
    for(auto l : a){
        for(auto r : b){
            res.push_back({l.first + r.first , mult(l.second , r.second)});
        }
    }
    return res;
}
int ncr(long long n , long long r){
    if(r < 0){
        return 0;
    }
    if(r > n){
        return 0;
    }
    long long num = ifact[n - r];
    for(long long i = r + 1 ; i <= n ; ++i){
        num = mult(num , i % mod);
    }
    return num;
}
int get(long long den){
    return ncr(n + den - 1 , den);
}
int main(){
    pre();
    cin >> n >> s;
    poly.push_back({0 , 1});
    for(int i = 1 ; i <= n ; ++i){
        cin >> f;
        poly = mult(poly , vector < pair < long long , int > > {{0 , 1} , {f + 1 , mod - 1}});
    }
    for(auto it : poly){
        ans = add(ans , mult(it.second , get(s - it.first)));
    }
    cout << ans << endl;
}