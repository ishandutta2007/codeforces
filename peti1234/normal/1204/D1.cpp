#include <bits/stdc++.h>

using namespace std;
string s;
int n;
bool v[100001]; vector<int> p;
int main()
{
    cin >> s;
    n=s.size();
    for (int i=0; i<n; i++) {
        char c=s[i];
        if (c=='1') {
            p.push_back(i);
        } else if (p.size()>0) {
            v[p.back()]=1;
            p.pop_back();
        }
    }
    for (int i=0; i<n; i++) {
        cout << v[i];
    }
    return 0;
}