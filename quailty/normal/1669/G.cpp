#include<bits/stdc++.h>
using namespace std;
const int MAXN=55;
char str[55][55];
void solve()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",str[i]);
    while(1)
    {
        bool change=0;
        for(int i=n-2;i>=0;i--)
            for(int j=0;j<m;j++)
            {
                if(str[i][j]=='*' && str[i+1][j]=='.')
                    swap(str[i][j],str[i+1][j]),change=1;
            }
        if(!change)break;
    }
    for(int i=0;i<n;i++)
        printf("%s\n",str[i]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}