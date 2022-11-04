#include <bits/stdc++.h>
using namespace std;
const int MAXM=1005;
char str[MAXM];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,x,y,res=0;
        scanf("%d%d%d%d",&n,&m,&x,&y);
        y=min(y,2*x);
        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            int cnt=0;
            for(int j=0;j<m;j++)
            {
                if(str[j]=='.')cnt++;
                else res+=cnt/2*y+cnt%2*x,cnt=0;
            }
            res+=cnt/2*y+cnt%2*x;
        }
        printf("%d\n",res);
    }   
    return 0;
}