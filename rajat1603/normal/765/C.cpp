#include "bits/stdc++.h"
using namespace std;
int k , a , b;
int main(){
    cin >> k >> a >> b;
    if(max(a , b) < k){
        cout << "-1\n";
    }
    else{
        if(a < b){
            swap(a , b);
        }
        int ans = 0;
        if(b >= k){
            ans += a / k;
            ans += b / k;
        }
        else{
            if(a % k){
                ans = -1;
            }
            else{
                ans += a / k;
                ans += b / k;
            }
        }
        cout << ans << endl;
    }
}