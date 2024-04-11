#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n], b[n], pos[n];

    for(int i = 0; i<n; i++){
        cin >> a[i];
        pos[a[i] - 1] = i;
    }

    for(int i = 0; i<n; i++){
        cin >> b[i];
    }

    int ma = n;
    int ans = 0;
    for(int i = n - 1; i>=0; i--){
        if(pos[b[i] - 1] >= ma) ans++;
        ma = min(ma, pos[b[i] - 1]);
    }

    cout << ans << endl;




}