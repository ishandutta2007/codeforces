#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>=65 && s[i]<=90) s[i]+=32;
    }
    string wynik="";
    for(int i =0;i<s.length();i++)
    {
        if(s[i]!='a' && s[i]!='o' && s[i]!='y' && s[i]!='i' && s[i]!='e' && s[i]!='u') wynik+=s[i];
    }
    string odp="";
    for(int i=0;i<wynik.length();i++)
    {
        odp+=".";
        odp+=wynik[i];
    }
    cout<<odp;
    return 0;
}