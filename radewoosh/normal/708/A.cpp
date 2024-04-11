#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    cin >> s;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]>'a')
        {
            for (int j=i; j<s.size() && s[j]!='a'; j++)
                s[j]--;
            cout << s << endl;
            return 0;
        }
    }
    s[s.size()-1]='z';
    cout << s << endl;
    return 0;
}