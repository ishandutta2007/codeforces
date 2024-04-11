#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){

    int n, d;
    cin >> n >> d;
    int a[n];

    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    for(int i = 0; i<d; i++){
        for(int j = 1; j<n; j++){
            if(a[j]){
                a[j] --;
                a[j - 1]++;
                break;
            }
        }
    }

    cout << a[0] << endl;

    }
}