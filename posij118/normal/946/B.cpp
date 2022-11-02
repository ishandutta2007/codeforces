#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int b, a, k;
    int x=0;
    cin >> a >> b;

    while(a > 0 && b > 0){

    if(a > b){
            swap(a, b);
            x++;
    }

    k=b/a;
    if(k%2==0) b-=k*a;
    else if(k==1){
        if(x%2==1) swap(a, b);
        cout << a << " " << b;
        return 0;
    }

    else b-=(k-1)*a;

    }

    if(x%2==1) swap(a, b);
        cout << a << " " << b;

}