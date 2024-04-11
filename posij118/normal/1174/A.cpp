#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[2*n];
    for(int i = 0; i<2*n; i++){
        cin >> a[i];
    }

    sort(a, a + 2*n);
    int cnt1, cnt2;
    cnt1 = 0;
    cnt2 = 0;

    for(int i = 0; i<n; i++){
        cnt1 += a[i];
    }

    for(int i = 0; i<n; i++){
        cnt2 += a[i + n];
    }

    if(cnt1 == cnt2){
        cout << -1;
        return 0;
    }

    for(int i = 0; i<2*n; i++){
        cout << a[i] << " ";
    }

}