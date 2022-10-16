#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=111;
int a[nax][nax];

int main()
{
    int n,m,h; cin>>n>>m>>h;
    int *k=new int[m];
    for(int i=0;i<m;i++) cin>>k[i];
    int *w=new int[n];
    for(int i=0;i<n;i++) cin>>w[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==0) cout<<"0"<<" ";
            else
            {
                cout<<min(k[j],w[i])<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}