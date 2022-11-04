#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int w[MAXN];
char str[MAXN<<1];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    scanf("%s",str);
    set<pair<int,int> > in,ex;
    for(int i=1;i<=n;i++)
        in.insert({w[i],i});
    for(int i=0;str[i];i++)
    {
        if(str[i]=='0')
        {
            printf("%d ",in.begin()->second);
            ex.insert(*in.begin());
            in.erase(in.begin());
        }
        else
        {
            printf("%d ",(--ex.end())->second);
            ex.erase(--ex.end());
        }
    }
    return 0;
}