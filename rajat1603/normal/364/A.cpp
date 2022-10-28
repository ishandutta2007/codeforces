#include "bits/stdc++.h"
using namespace std;
const int N = 1 << 12;
int a;
string str;
int n;
long long ans;
int cnt[9 * N] = {0};
int main(){
    cin >> a;
    cin >> str;
    n = str.size();
    str = " " + str;
    for(int i = 1 ; i <= n ; ++i){
        int sum = 0;
        for(int j = i ; j <= n ; ++j){
            sum += str[j] - '0';
            ++cnt[sum];
        }
    }
    if(!a){
        ans = (1LL * n * (n + 1) * cnt[0]) - (1LL * cnt[0] * cnt[0]);
    }
    else{
        for(int i = 1 ; i * i <= a ; ++i){
            if(a % i == 0){
                ans += 1LL * (1 + (i * i != a)) * cnt[i] * (((a / i) > 9 * n) ? 0 : cnt[a / i]);
            }
        }
    }
    cout << ans;
}