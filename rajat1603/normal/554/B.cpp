#include "bits/stdc++.h"
using namespace std;
string t;
map < string  , int > m;
int n;
int ans = 1;
int main(){
    cin >> n;
    while(n--){
        cin >> t;
        m[t]++;
    }
    for(auto it : m){
        ans = max(ans , it.second);
    }
    cout << ans;
}