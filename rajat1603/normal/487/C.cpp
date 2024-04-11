#include "bits/stdc++.h"
using namespace std;
int n;
long long power(int aa , int b){
    long long res = 1 , a = aa;
    while(b){
        if(b & 1){
            res *= a;
            res %= n;
        }
        a *= a;
        a %= n;
        b >>= 1;
    }
    return res;
}
long long inv(int b){
    return power(b , n - 2);
}
set < int > s;
vector < int > v;
int main(){
    cin >> n;
    if(n == 1){
        cout << "YES\n1";
        return 0;
    }
    else if(n == 4){
        cout << "YES\n1 3 2 4";
        return 0;
    }
    s.insert(1);
    v.emplace_back(1);
    for(int i = 2 ; i < n ; ++i){
        int temp = (inv(i - 1) * i) % n;
        s.insert(temp);
        v.emplace_back(temp);
    }
    s.insert(n);
    v.emplace_back(n);
    if(s.size() == n){
        cout << "YES\n";
        for(int x : v){
            cout << x << endl;
        }
    }
    else{
        cout << "NO";
    }
}