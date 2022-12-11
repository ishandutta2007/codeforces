#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    int k = 0;
    while(a <= b){
        a *= 3;
        b *= 2;
        k++;
    }
    cout << k;
    return 0;
}