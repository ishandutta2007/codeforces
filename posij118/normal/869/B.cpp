#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int a, b, mu;
    cin >> a >> b;
    if(b-a>=20){
        cout << "0";
    }

    else{
        mu=1;
        for(long long int i=b; i>a; i--){
            mu*=(i%10);
        }

        cout << mu % 10;
    }

}