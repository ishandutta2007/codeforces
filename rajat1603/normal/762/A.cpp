#include "bits/stdc++.h"
using namespace std;
vector < long long > v;
long long n;
int k;
int main(){
    cin >> n >> k;
    v.clear();
    for(int i = 1 ; 1LL * i * i <= n ; ++i){
        if(n % i == 0){
            v.emplace_back(i);
            if(i != (n / i)){
                v.emplace_back(n / i);
            }
        }
    }
    sort(v.begin() , v.end());
    if(v.size() < k){
        cout << "-1\n";
    }
    else{
        cout << v[k - 1] << "\n";
    }
}