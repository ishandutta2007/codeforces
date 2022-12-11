#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ios_base::sync_with_stdio(false);cin.tie(false);
    int n,d;
    cin >> n >> d;
    int k;
    int jokes = 0;
    cin >> k;
    d-=k;
    if(d<0){
        cout << -1;
        exit(0);
    }
    for(int i = 1;i<n;i++){
        cin >> k;
        //cout << d << " " << k+10 << "\n";
        if(d>=k+10){
            d -= k+10;
            jokes+=2;
        }
        else{
            cout << -1;
            exit(0);
        }
    }
    cout << jokes+(d/5);
    return 0;
}