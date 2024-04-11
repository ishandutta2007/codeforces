#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> head;
int l[105],r[105];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d",l+i,r+i);
        if(l[i]==0)
        {
            head.push_back(i);
        }
    }
    for(int i=0;i+1<(int)head.size();++i)
    {
        int now=head[i];
        int nxt=head[i+1];
        while(r[now]) now=r[now];
        r[now]=nxt;
        l[nxt]=now;
    }
    for(int i=1;i<=n;++i)
    {
        printf("%d %d\n",l[i],r[i]);
    }
}