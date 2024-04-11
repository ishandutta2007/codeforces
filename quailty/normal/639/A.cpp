#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
set<pair<int,int> >st;
int a[150005];
int main()
{
    int n,k,q;
    scanf("%d%d%d",&n,&k,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=q;i++)
    {
        int ty,id;
        scanf("%d%d",&ty,&id);
        if(ty==1)
        {
            st.insert(make_pair(a[id],id));
            if((int)st.size()>k)st.erase(st.begin());
        }
        else
        {
            bool isok=0;
            for(auto itr=st.begin();itr!=st.end();itr++)
                isok|=(itr->second ==id);
            printf("%s\n",(isok ? "YES" : "NO"));
        }
    }
    return 0;
}