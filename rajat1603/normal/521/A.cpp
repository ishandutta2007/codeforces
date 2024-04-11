#include "bits/stdc++.h"
using namespace std;
const int N = 100001;
const int mod = 1e9 + 7;
string str;
int n;
int cnt[26]={0};
int counter = 0;
int mx = 0;
long long res = 1;
int main(){
    cin >> n;
    cin >> str;
    for(int i = 0 ; i < n ; ++i){
        cnt[str[i] - 'A']++;
        mx = max(mx , cnt[str[i] - 'A']);
    }
    for(int i = 0 ; i < 26 ; ++i){
        counter += ( cnt[i] == mx );
    }
    while(n--){
        res *= counter;
        res %= mod;
    }
    cout << res ;
}