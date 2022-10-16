#include <iostream>

using namespace std;

int main()
{
    int n;
    string s;
    cin>>n;
    cin>>s;
    int licznik=0;
    int i=0;
    while(i<n-1)
    {
        if(s[i]!=s[i+1]) {licznik++; i++;}
        i++;
    }
    cout<<n-licznik;
    return 0;
}