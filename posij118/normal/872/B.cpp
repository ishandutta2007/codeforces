#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, ma, pos, mi;
    ma=-1000000007;
    mi=1000000007;
    cin >> n >> k;

    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
        ma=max(ma, a[i]);
        if(ma==a[i]) pos=i;
        mi=min(mi, a[i]);
    }

    if(k>=3) cout << ma;
    else if(k==1) cout << mi;
    else cout << max(a[0], a[n-1]);

}