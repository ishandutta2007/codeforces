#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int a, b, sum;
    sum=0;
    cin >> a >> b;
    while(a<=b){
        a=3*a;
        b=2*b;
        sum+=1;
    }
    cout << sum << endl;
}