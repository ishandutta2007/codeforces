#include <iostream>

using namespace std;

int main()
{
    int n,k;
    int * tab[4];
    cin>>n>>k;
    for(int i=0;i<4;i++)
    {
        tab[i]=new int[n];
    }
    for (int i=0;i<4;i++)
    {
        for(int j=0;j<n;j++)
        {
            tab[i][j]=0;
        }
    }
    if  (k>2*(n-2)) {cout<<"NO";}
    else
    {
        int licznik=1;
        while(k>1 && licznik<=(n-2)/2)
        {

            tab[1][licznik]=1;
            tab[1][n-licznik-1]=1;
            k-=2;
             licznik++;
        }
        licznik=1;
        while(k>1 && licznik<=(n-2)/2)
        {

            tab[2][licznik]=1;
            tab[2][n-licznik-1]=1;
            k-=2;
             licznik++;
        }
        if(k==2) {tab[1][n/2]=1; tab[2][n/2]=1;}
        if(k==1) {tab[1][n/2]=1;}

         cout<<"YES"<<endl;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(tab[i][j]==0) cout<<".";
            else cout<<"#";
        }
        cout<<endl;
    }
    }



    for(int i=0;i<4;i++)
    {
        delete [] tab[i];
    }

    return 0;
}