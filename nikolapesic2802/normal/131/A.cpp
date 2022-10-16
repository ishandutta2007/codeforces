#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    string s;
    cin >> s;
    string s1;
    if(s[0]<'a')
    {
        s1+=s[0]-'A'+'a';
    }
    else
        s1+=s[0]-'a'+'A';
    bool test=true;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]>='a')
        {
            test=false;
        }
        s1+=s[i]-'A'+'a';
    }
    if(!test)
    {
        cout << s;
        return 0;
    }
    cout << s1;
    return 0;
}