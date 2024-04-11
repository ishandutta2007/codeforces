#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    int cnt = 0;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        if(a[i] % 2) cnt++;
    }

    if(!(cnt == 0 || cnt == n)){
        sort(a, a + n);
    }

    for(int i = 0; i<n; i++){
        cout << a[i] << " ";
    }

}