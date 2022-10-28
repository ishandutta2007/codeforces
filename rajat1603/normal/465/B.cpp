#include "bits/stdc++.h"
using namespace std;
const int N = 1005;
int n;
bool arr;
int last = 0;
int ans = 0;
int lol = 1;
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr;
        if(arr){
            ans += min(lol , min(2 , i - last));
            last = i;
            lol = 1e9;
        }
    }
    cout << ans;
}