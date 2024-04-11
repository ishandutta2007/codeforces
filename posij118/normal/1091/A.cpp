#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    c-=2;
    b-=1;
    cout << 3*(min(min(a, b), c)) + 3;

}