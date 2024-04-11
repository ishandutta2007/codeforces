#include <iostream>

using namespace std;


int main()
{
    int n;
    string s;
    cin>>n;
    cin>>s;
    int j;
    int wynik=0;
    for(int i=1;i<=n/2;i++)
    {
        bool xd=true;
        for(j=0;j<i;j++)
        {
            if(s[j]!=s[j+i]) {xd=false;}
        }
        if(xd)
        {
            wynik=j;
        }

    }
    if(wynik==0) cout<<s.length();
    else cout<<s.length()-wynik+1;

    return 0;
}