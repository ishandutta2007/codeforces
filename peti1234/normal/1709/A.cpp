#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        cout << (n==1 && a==0 || n==2 && b==0 || n==3 && c==0 || a==1 || b==2 || c==3 ? "NO" : "YES") <<"\n";
 
    }
    return 0;
}