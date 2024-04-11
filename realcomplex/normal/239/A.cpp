#include <bits/stdc++.h>

using namespace std;

int main()
{
    int y,k,n;
    cin >> y >> k >> n;
    bool is = false;
    for(int i = 1;i<=n/k;i++){
        if((k*i)<=n && i*k>y){
            cout << abs((k*i)-y) << " ";
            is = true;
        }
    }
    if(is == false) cout << -1;
    return 0;
}