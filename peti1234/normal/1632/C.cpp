#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w, a, b;
    cin >> w;
    while (w--) {
        cin >> a >> b;
        int ans=b-a, fb=0;
        for (int i=0; i<=b; i++) {
            ans=min({ans, i+1+((a+i) | b)-b, i+1+(a | (b+i))-b-i});
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
1
2 5
*/