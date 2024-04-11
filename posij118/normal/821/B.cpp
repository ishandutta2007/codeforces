#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    long long int m, b, x, y, maxi;
    maxi=0;
    cin >> m >> b;

    for(long long int i=0; i<b+1; i++){
        y=i;
        x=m*(b-i);
        maxi=max(maxi, ((x+1)*(y+1)*(x+y))/2);
    }

    cout << maxi;
}