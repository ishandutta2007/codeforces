#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, n, a;
    a=1;
    cin >> m >> n;

    while(m>=0 && n>=0){
        if(a%2==1){
            m-=a;
            a++;
        }

        else{
            n-=a;
            a++;
        }
    }

    if(m<0) cout << "Vladik";
    else cout << "Valera";

}