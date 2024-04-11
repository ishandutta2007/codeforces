#include <iostream>

using namespace std;

int main()
{

    bool xd=true;
           int n;
    cin>>n;
    char * wyraz;
    wyraz=new char[n];
    for(int i=0;i<n;i++)
    {
        cin>>wyraz[i];
    }

    for(int i=0;i<n-1;i++)
    {
        if(wyraz[i]==wyraz[i+1] && wyraz[i]!='?' && xd==true ) {cout<<"No"; xd=false;}



    }
    if(wyraz[0]=='?' || wyraz[n-1]=='?') {if(xd){cout<<"Yes"; xd=false;} }
    for(int i=1;i<n-1;i++)
    {
        if(wyraz[i]=='?')
        {
            if(wyraz[i+1]!='?' && wyraz[i-1]!='?' && wyraz[i+1]!=wyraz[i-1]) {;}
            else {if(xd){cout<<"Yes"; xd=false;} }
        }
    }


    if(xd)
    {
        cout<<"No";
    }


    delete [] wyraz;

    return 0;
}