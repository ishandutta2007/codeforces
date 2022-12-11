#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ios_base::sync_with_stdio(false);cin.tie(false);
    int n,c;
    cin >> n >> c;
    int sk[n];
    for(int j = 0;j<n;j++){
        cin >> sk[j];
    }
    int am = 1;
    for(int j = 1;j<n;j++){
        if(sk[j]-sk[j-1]>c){
            am = 1;
        }
        else{
            am++;
        }
    }
    cout << am;
    return 0;
}