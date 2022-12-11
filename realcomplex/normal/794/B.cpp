#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);
    double n,h;
    cin >> n >> h;
    for(int j = 1;j<n;j++){
        cout << fixed << setprecision(7) << sqrt(j/n)*h << " ";
    }
    return 0;
}