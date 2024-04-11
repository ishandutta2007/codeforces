#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin >> n >> k;
    if(n==k||k==0){
        cout << "0 ";
    }
    else{
        cout << "1 ";
    }
    cout << min(k*2,n-k);
    return 0;
}