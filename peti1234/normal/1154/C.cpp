#include <bits/stdc++.h>

using namespace std;
int t[3], h, maxi;
vector<int> v={0, 1, 2, 0, 2, 1, 0};
int main()
{
    cin >> t[0] >> t[1] >> t[2];
    h=min({t[0]/3, t[1]/2, t[2]/2});
    t[0]-=3*h, t[1]-=2*h, t[2]-=2*h;
    for (int i=0; i<7; i++) {
        int s[3]={0, 0, 0};
        for (int j=i; ; j++) {
            int f=v[j%7];
            if (++s[f]>t[f]) break;
            maxi=max(maxi, j-i+1);
        }
    }
    cout << 7*h+maxi << "\n";
    return 0;
}