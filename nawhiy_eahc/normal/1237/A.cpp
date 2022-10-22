#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; bool f = false;

    cin >> n;
    for(int i=1;i<=n;i++){
        int k; cin >> k;
        if(k%2 == 0) cout << k/2 << "\n";
        else{
            if(f) cout << (k+1)/2 << "\n";
            else cout << (k-1)/2 << "\n";
            f = !f;
        }
    }
}