#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second

int main(){

    int n,k;
    cin >> n >> k;
    int h = (n/2) + (n%2);
    int mn = 1e9;
    while(n>h){
        if(n%k==0){
            mn = min(mn,n);
        }
        n--;
    }
    if(n%k==0){
        mn = min(mn,n);
    }
    if(mn != 1e9){
        cout << mn;
    }
    else{
        cout << -1;
    }
    return 0;
}