#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    if(n%2==1){
        cout << n/2 << " " << n/2+1;
    }
    else{
        if(n%4==0){
            cout << n/2-1 << " " << n/2+1;
        }
        else{
            cout << n/2-2 << " " << n/2+2;
        }
    }
    return 0;
}