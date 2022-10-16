#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int licznik=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='o') licznik++;
    }
    if(licznik==0) cout<<"YES";
    else{
        if(n%licznik==0) cout<<"YES";
    else cout<<"NO";
    }

    return 0;
}