#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=500005;
string str[MAXN];
void solve(int l,int r,int d)
{
    for(int i=l;i<=r;i++)
    {
        if(i==l)
        {
            if((int)str[i].size()==d)l++;
            continue;
        }
        if((int)str[i].size()==d || str[i][d]<str[i-1][d])
        {
            for(int j=l;j<i;j++)
                while((int)str[j].size()>d)str[j].pop_back();
            l=i--;
        }
    }
    for(int i=l,j=l;i<=r;i=j)
    {
        while(j<=r && str[j][d]==str[i][d])j++;
        solve(i,j-1,d+1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>str[i];
    solve(1,n,0);
    for(int i=1;i<=n;i++)
        cout<<str[i]<<"\n";
    return 0;
}