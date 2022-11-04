#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN=100005;
const int MAXM=100005;
struct edge
{
    int w,b,id;
    edge(){}
    edge(int _w,int _b,int _id):w(_w),b(_b),id(_id){}
    bool operator < (const edge &t)const
    {
        return w==t.w ? b>t.b : w<t.w;
    }
}e[MAXM];
pair<int,int>res[MAXM];
set<pair<int,int> >st;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int cnt=0;
    st.clear();
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&e[i].w,&e[i].b);
        cnt+=e[i].b;
        e[i].id=i;
    }
    if(cnt!=n-1)printf("-1\n");
    else
    {
        sort(e+1,e+m+1);
        bool isok=1;
        int now=1,all=0;
        for(int i=1;i<=m;i++)
        {
            if(e[i].b==1)
            {
                now++;
                res[e[i].id]=make_pair(1,now);
                for(int i=2;i<now && all<=m;i++)
                {
                    all++;
                    st.insert(make_pair(i,now));
                }
            }
            else
            {
                if((int)st.size()==0)
                {
                    isok=0;
                    break;
                }
                res[e[i].id]=*st.begin();
                st.erase(st.begin());
            }
        }
        if(!isok)printf("-1\n");
        else
        {
            for(int i=1;i<=m;i++)
                printf("%d %d\n",res[i].first,res[i].second);
        }
    }
    return 0;
}