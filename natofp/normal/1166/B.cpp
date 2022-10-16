#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=2005;
char tab[nax][nax];
vector<char> xd;

void dokoncz(int a,int b)
{
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            int numer;
            numer=(j+i)%5;
            tab[i][j]=xd[numer];
        }
    }
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            cout<<tab[i][j];
        }
    }
}


int main()
{

    xd.push_back('a');
    xd.push_back('e');
    xd.push_back('i');
    xd.push_back('o');
    xd.push_back('u');
    int n; cin>>n;
    for(int i=5;i<=n;i++)
    {
        if(n%i==0)
        {
            int ile=n/i;
            if(ile>=5)
            {
                dokoncz(i,n/i);
                return 0;
            }
            else
            {
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}