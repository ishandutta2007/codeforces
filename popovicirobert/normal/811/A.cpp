#include <bits/stdc++.h>
#define ll long long


using namespace std;




int main() {
   // fstream cin("A.in");
   // ofstream cout("A.out");
    int a, b;
    ios::sync_with_stdio(false);
    cin >> a >> b;
    int i = 1;
    while(a >= 0 && b >= 0) {
        if(i % 2 == 1)
            a -= i;
        else
            b -= i;
        i++;
    }
    if(a < 0)
        cout << "Vladik";
    else
        cout << "Valera";
    //cin.close();
    //cout.close();
    return 0;
}