#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){

    int n;
    cin >> n;

    int x[n];
    for(int i = 0; i<n; i++){
        cin >> x[i];
    }
    x[n - 1]++;
    int ans = 1;

    for(int i = n - 2; i>=0; i--){
        if(x[i] < x[i + 1] - 1) x[i]++;
        if(x[i] != x[i + 1]) ans++;
    }

    cout << ans << endl;

    }
}