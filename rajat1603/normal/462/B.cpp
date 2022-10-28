#include "bits/stdc++.h"
using namespace std;
long long ans = 0;
int n , k;
int cnt[26] = {0};
string str;
int main(){
    cin >> n >> k;
    cin >> str;
    for(char c : str){
        cnt[c - 'A']++;
    }
    sort(cnt , cnt + 26);
    for(int i = 25 ; i >= 0 && k ; --i){
        if(cnt[i] >= k){
            ans += 1LL * k * k;
            k = 0;
        }
        else{
            k -= cnt[i];
            ans += 1LL * cnt[i] * cnt[i];
        }
    }
    cout << ans;
}