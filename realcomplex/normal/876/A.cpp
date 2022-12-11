#include <bits/stdc++.h>

using namespace std;

int main(){
        int n;
        cin >> n;
        int a,b,c;
        cin >> a >> b >> c;
        if(n == 1) cout << 0;
        else cout << min(min(a,b)*(n-1),min(a,b)+(c*(n-2)));
        return 0;
}