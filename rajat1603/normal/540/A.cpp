#include "bits/stdc++.h"
using namespace std;
int n , ans = 0;
string a , b;
int main(){
    cin >> n >> a >> b;
    for(int i = 0 ; i < n ; ++i){
        if(a[i] > b[i]){
            swap(a[i] , b[i]);
        }
        ans += min(abs(b[i] - a[i]) , -abs(a[i] - b[i]) + 10);
    }
    cout << ans;
}