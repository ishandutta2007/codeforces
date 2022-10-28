#include "bits/stdc++.h"
using namespace std;
const long long N = 82;
long long power[N][6];
long long a , b , c;
vector < long long > ans;
void pre(){
    for(long long i = 1 ; i < N ; ++i){
        power[i][0] = 1;
        for(long long j = 1 ; j < 6 ; ++j){
            power[i][j] = power[i][j - 1] * i;
        }
    }
}
long long sum(long long num){
    long long res = 0;
    while(num){
        res += num % 10;
        num /= 10;
    }
    return res;
}
int main(){
    cin >> a >> b >> c;
    pre();
    for(long long i = 1 ; i < N ; ++i){
        long long x = b * power[i][a] + c;
        if(x > 0 && x < 1e9 && sum(x) == i){
            ans.emplace_back(x);
        }
    }
    cout << ans.size() << endl;
    for(auto it : ans){
        cout << it << " ";
    }
}