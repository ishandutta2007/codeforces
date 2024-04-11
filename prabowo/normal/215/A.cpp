#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    long a[55],b[55];
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    cin >> m;
    for(int i=0; i<m; i++) cin >> b[i];

    long ans = 0, cnt = 0;
    for(int i=0; i<m; i++) for(int j=0; j<n; j++) if (b[i] % a[j] == 0){if (b[i] / a[j] > ans){ans = b[i]/a[j]; cnt = 1;} else if (b[i]/a[j] == ans) cnt++;}

    cout << cnt << endl;

    return 0;
}