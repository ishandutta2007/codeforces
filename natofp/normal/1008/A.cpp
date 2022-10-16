#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    for(int i=1;i<s.length();i++)
    {
        if(s[i-1]!='a' && s[i-1]!='i' && s[i-1]!='e' && s[i-1]!='o' && s[i-1]!='u' && s[i-1]!='n')
        {
            if(s[i]!='a' && s[i]!='i' && s[i]!='e' && s[i]!='o' && s[i]!='u') {cout<<"NO"; return 0;}
        }
    }
    int n=s.length()-1;
    if(s[n]!='a' && s[n]!='e' && s[n]!='i' && s[n]!='o' && s[n]!='u' && s[n]!='n')  {cout<<"NO"; return 0;}
    cout<<"YES";
    return 0;
}