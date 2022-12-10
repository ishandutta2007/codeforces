#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, r;
    cin >> a >> b >> r;
    if(r * 2 > min(a, b))
        cout << "Second" << endl;
    else
        cout << "First" << endl;
    return 0;
}