#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        if(a%2 != b%2)
        {
            cout << "-1\n";
            continue;
        }
 
        if(a == b && a == 0)
        {
            cout << "0\n";
            continue;
        }
 
        if(a == b)
        {
            cout << "1\n";
            continue;
        }
 
        cout << "2\n";
    }
}