#include <iostream>

using namespace std;

int main()
{
     int n;
    cin>>n;
    bool prawda=true;

    string tab;
    cin>>tab;
    if(n==1)
    {
        if(tab[0]=='1') cout<<"Yes";
        else cout<<"No";
    }
    else{
        for(int i=1;i<n;i++)
    {
        if(tab[i]=='1' && tab[i-1]=='1') prawda=false;
    }
    for(int i=1;i<n-1;i++)
    {

        if(tab[i]=='0' && tab[i-1]=='0' && tab[i+1]=='0') prawda=false;
    }
    if(tab[0]=='0' && tab[1]=='0') prawda=false;
    if(tab[n-1]=='0' && tab[n-2]=='0') prawda=false;
    if(prawda) cout<<"Yes";
    else cout<<"No";
    }

    return 0;
}