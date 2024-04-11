#include <bits/stdc++.h>

using namespace std;
int n;
string s;
bool p[30];
int main()
{
    cin >> s >> n;
    for (int i=0; i<s.size(); i++) {
        p[s[i]-'a']=true;
    }
    int a=0;
    for (int i=0; i<=29; i++) {
        a+=p[i];
    }
    if (n>s.size()) {
        cout << "impossible";
    } else {
        n=max(n, a);
        cout << n-a;
    }
    return 0;
}