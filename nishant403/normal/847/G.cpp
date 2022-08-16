#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int main()
{
    int n;
    cin>>n;
    char a[n][7];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<7;j++)
        {
            cin>>a[i][j];
        }
    }
    int ma=0;
    for(int i=0;i<7;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
          count+=a[j][i]-'0';  
        }
        ma=max(ma,count);
    }
    cout<<ma<<endl;
}