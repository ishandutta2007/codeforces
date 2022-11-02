#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n, m;
    int x=1;
    cin >> n >> m;

    if(n>=30) cout << m;
    else{
        for(int i=0; i<n; i++){
            x*=2;
        }

        cout << m%x;
    }



}