#include <bits/stdc++.h>
using namespace std;
string small(string s)
{
    if(s.length()%2==1)
        return s;
    string s1 = small(string(s.substr(0, s.length()/2)));
    string s2 = small(string(s.substr(s.length()/2, s.length()/2)));
    //cout << s1 << " " << s2 << "\n";
    if(s1<s2)
        return s1+s2;
    else return s2+s1;
}
int main()
{
    int l, i, j, y;
    string a, b;
    while(cin>>a>>b)
    {
        a=small(a);
        b=small(b);
        if(a==b)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}