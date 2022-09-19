#include <bits/stdc++.h>

using namespace std;
int n, cnt, mini, kezd=-1, veg=-1;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    for (int i=0; i<n; i++) {
        if (s[i]=='(') cnt++;
        if (s[i]==')') {
            cnt--;
            mini=min(mini, cnt);
            if (cnt<0 && kezd==-1) {
                kezd=i;
            }
            if (cnt<=1) {
                veg=i;
            }
        }
    }
    if (cnt==-2 && mini==-2) {
        cout << kezd/2+1 << "\n";
        return 0;
    }
    if (cnt==2 && mini==0) {
        cout << (n-veg)/2 << "\n";
        return 0;
    }
    cout << 0 << "\n";
    return 0;
}