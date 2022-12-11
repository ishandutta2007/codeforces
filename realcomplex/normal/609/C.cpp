#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

int main(){

    int n;
    cin >> n;
    int k[n];
    int sum = 0;
    int mod;
    for(int i = 0;i<n;i++){
        cin >> k[i];
        sum += k[i];
    }
    mod = sum%n;
    sum /= n;
    int atl = 0;
    for(int i = n-1;i>=0;i--){
        if(k[i] > sum){
            if(mod>0){
                atl += k[i]-(sum+1);
                k[i] = sum+1;
                mod--;
            }
            else{
                atl += k[i]-sum;
                k[i] = sum;
                mod--;
            }
        }
    }
    cout << atl;
    return 0;
}