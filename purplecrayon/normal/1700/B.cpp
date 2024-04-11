#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n; cin >> n;
    vector<int> num(n);
    for(int i= 0; i < n; i++){
        char a; cin >> a;
        num[i] = a-'0';
    }
    vector<int> ans(n);
    if(num[0] > 2){
        //do 1111
        bool carry = 0;
        for(int i = n-1; i >= 0; i--){
            int cur = 1;
            if(carry){
                cur = 0; carry = 0;
            }
            if(num[i] > cur){
                cur += 10; carry = 1;
            }
            ans[i] = cur-num[i];
        }
        for(int i = 0; i < n; i++) cout << ans[i];
        cout << "\n";
        return;
    }else{
        //do 9999
        for(int i = 0; i < n; i++) cout << 9-num[i];
        cout << "\n";
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}