#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, cnt, x, y;
    cnt = 0;
    cin >> n;

    int a[n];
    int inv[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
        a[i]--;
        inv[a[i]]=i;
    }

    for(int i=0; i<n; i++){
        if(a[i] != i){
            x = inv[i];
            swap(inv[a[i]], inv[i]);
            swap(a[i], a[x]);
            cnt++;
        }
    }

    if(n % 2 == cnt % 2) cout << "Petr";
    else cout << "Um_nik";


}