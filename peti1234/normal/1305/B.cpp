#include <bits/stdc++.h>

using namespace std;
string s;
bool v[1001];
vector<int> p;
int db=1, n;
int main()
{
    cin >> s;
    n=s.size();
    while(true) {
        int kezd=1001, veg=-1;
        for (int i=0; i<n; i++) if (!v[i] && s[i]=='(') {
             kezd=i;
             break;
        }
        for (int i=n-1; i>=0; i--) if (!v[i] && s[i]==')') {
            veg=i;
            break;
        }
        if (kezd<veg) v[kezd]=1, v[veg]=1, p.push_back(kezd), p.push_back(veg);
        else break;
    }
    if (p.size()==0) {
        cout << 0; return 0;
    }
    cout << 1 << "\n";
    cout << p.size() << "\n";
    sort(p.begin(), p.end());
    for (int i=0; i<p.size(); i++) cout << p[i]+1 << " ";
    return 0;
}