#include <bits/stdc++.h>

using namespace std;
long long w, d, s, k;
int main()
{
    cin >> w;
    while(w--) {
        cin >> d >> k;
        d*=d;
        s=d/2; s=sqrt(s);
        s/=k, s*=k;
        if (s*s+(s+k)*(s+k)<=d) cout << "Ashish\n";
        else cout << "Utkarsh\n";
    }
    return 0;
}