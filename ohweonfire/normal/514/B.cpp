#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
set<pair<int,int> > st;
int xx,yy,n;
int main()
{
    scanf("%d%d%d",&n,&xx,&yy);
    for(int i=1;i<=n;i++)
    {
        int x,y,g;
        bool neg=false;
        scanf("%d%d",&x,&y);
        x=xx-x;
        y=yy-y;
        if(x==0&&y==0)
        {
            st.insert(make_pair(0,0));
            continue;
        }
        if(x<0&&y>0)
        {
            x=-x;
            neg=true;
        }
        if(x>0&&y<0)
        {
            y=-y;
            neg=true;
        }
        if(x<0&&y<0)
        {
            x=-x;
            y=-y;
        }
        if(x!=0&&y!=0)
            g=__gcd(x,y);
        else
            g=x+y;
        st.insert(make_pair(x/g*(neg?-1:1),y/g));
    }
    if(st.count(make_pair(0,0))&&st.size()!=1)
        st.erase(make_pair(0,0));
    printf("%d\n",st.size());
    return 0;
}