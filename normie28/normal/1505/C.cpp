#include <bits/stdc++.h> 
using namespace std;
string s;
int main()
{
    cin>>s;
    for (int i=2;i<s.length();i++)
    {
        int a=s[i]-65;
        int b=s[i-1]-65;
        int c=s[i-2]-65;
        if ((b+c)%26==a);
        else
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}