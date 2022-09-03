#include <iostream>
using namespace std;
int n,m;
bool row[15],col[15];
char str[15][15];
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>str[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
                if(str[i][j]=='S')row[i]=col[j]=true;
    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
                if(!row[i]||!col[j])ans++;
    cout<<ans;
    return 0;
}