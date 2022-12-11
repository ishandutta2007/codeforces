#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ios_base::sync_with_stdio(false);cin.tie(false);
    int n;
    cin >> n;
    int c[n];
    int p = 0;
    for(int j = 0;j<n;j++){
        cin >> c[j];
        p += c[j];
    }
    if(p == n){
        cout << n-1;
        return 0;
    }
    int s = 0;
    int g = 0;
    for(int j = 0;j<n;j++){
        if(c[j] == 0){
            if(s<0){
                s = 0;
            }
            s++;
        }
        else{
            s--;
        }
        g = max(g,s);
    }
    cout << p+g;
    return 0;
}