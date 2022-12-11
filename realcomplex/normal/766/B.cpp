#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    int c[n];
    for(int i = 0;i<n;i++){
        cin >> c[i];
    }
    sort(c,c+n);
    for(int j = 0;j<=n-3;j++){
        if(c[j]+c[j+1]>c[j+2]){
            cout << "YES";
            exit(0);
        }
    }
    cout << "NO";
    return 0;
}