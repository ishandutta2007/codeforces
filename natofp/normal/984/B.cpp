
#include <bits/stdc++.h>
using namespace std;




int main()
{
    bool wynik=true;
    int n,m;
    cin>>n>>m;
    char ** tab;
    tab=new char*[n];
    for(int i=0;i<n;i++)
        tab[i]=new char [m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>tab[i][j];
    }
  for(int i=0;i<n;i++)
    {

        for(int j=0;j<m;j++)
            if(tab[i][j]!='*')
            {
                int licznik=0;
                for(int k=-1;k<=1;k++)
                {
                    for(int h=-1;h<=1;h++)
                    {
                        if(i+k>=0 && i+k<n && j+h>=0 && j+h<m)
                            if(tab[i+k][j+h]=='*') licznik++;
                    }
                }

                if(tab[i][j]=='.' && licznik!=0) wynik=false;
                else if(tab[i][j]-48!=licznik && tab[i][j]!='.') wynik=false;

            }
    }


    if(wynik) cout<<"YES";
    else cout<<"NO";
    return 0;
}