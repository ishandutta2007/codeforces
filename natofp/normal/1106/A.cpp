#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char a[555][555];

bool czy(int i,int j)
{
    if(a[i][j]==a[i+1][j+1] && a[i][j]==a[i+2][j+2] && a[i][j]==a[i+2][j] && a[i][j]==a[i][j+2] && a[i][j]=='X') return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    int res=0;
    for(int i=0;i<n-2;i++)
    {
        for(int j=0;j<n-2;j++)
        {
            if(czy(i,j)) res++;
        }
    }
    cout<<res<<endl;
    return 0;
}