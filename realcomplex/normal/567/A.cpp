#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    int c[n];
    for(int i = 0;i<n;i++){
        cin >> c[i];
    }
    int fx,sx;
    fx = c[0];
    sx = c[n-1];
    for(int j = 0;j<n;j++){
        if(j == 0){
            cout << c[1]-c[0] << " " << c[n-1]-c[0]<< "\n";
            continue;
        }
        else if(j == n-1){
            cout << c[j]-c[j-1] << " " << c[j]-c[0] << "\n";
            continue;
        }
        cout << min(abs(c[j]-c[j-1]),abs(c[j]-c[j+1])) << " " << max(abs(c[j]-fx),abs(c[j]-sx)) << "\n";
    }
    return 0;
}