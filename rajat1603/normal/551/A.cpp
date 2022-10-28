#include "bits/stdc++.h"
using namespace std;
int n;
int main(){
    cin >> n;
    vector < int > v(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> v[i];
    }
    for(int i : v){
        int ans = 1;
        for(int j : v){
            ans += j > i;
        }
        cout << ans << " ";
    }
}