#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n%10>4) cout << n+10-(n%10);
    else cout << n-(n%10);

}