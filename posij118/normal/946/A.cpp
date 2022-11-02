#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int ans=0;
    cin >> n;

    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
        ans+=abs(a[i]);
    }

    cout << ans;

}