#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n,i,j,d[10],m;
char c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i=0; i<n; i++){
        for(j=0; j<7; j++)
            cin >> c, d[j] += (c - 48);
    }
    for(i=0; i<7; i++)
        m = max(m, d[i]);
    cout << m;
    return 0;
}