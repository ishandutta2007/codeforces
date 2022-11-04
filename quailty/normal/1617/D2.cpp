#include<bits/stdc++.h>
using namespace std;

inline int query(int a,int b,int c)
{
    printf("? %d %d %d\n",a,b,c);
    fflush(stdout);
    int res;
    scanf("%d",&res);
    return res;
}

inline void answer(const vector<int>& imp)
{
    printf("! %d",(int)imp.size());
    for(auto t : imp)printf(" %d",t);
    printf("\n");
    fflush(stdout);
}

int solve()
{
    int n;
    scanf("%d",&n);
    vector<int> group(n/3);
    for(int i=0;i<n/3;i++) // n/3 queries
        group[i]=query(3*i+1,3*i+2,3*i+3);
    int x=find(group.begin(),group.end(),0)-group.begin();
    int y=find(group.begin(),group.end(),1)-group.begin();
    int go[4]={3*x+2,3*x+3,3*y+2,3*y+3};
    vector<int> res(4);
    int p=3*x+1,q=3*y+1,mask=0;
    for(int i=0;i<4;i++) // 4 queries
    {
        res[i]=query(p,q,go[i]);
        mask|=(1<<res[i]);
    }
    vector<int> imp;
    if(mask==1)q++;
    else if(mask==2)p++;
    else
    {
        int pp=0,qq=0;
        for(int i=0;i<4;i++)
        {
            if(res[i]==0)pp=go[i];
            else qq=go[i];
        }
        assert(pp && qq);
        if(query(pp,qq,q)==0)p++,q++; // 1 query
    }
    for(int i=0;i<n/3;i++) // 2n/3 queries
    {
        if(group[i]==0)
        {
            if(query(q,3*i+1,3*i+2)==0)
            {
                imp.push_back(3*i+1);
                imp.push_back(3*i+2);
                if(p==3*i+3 || query(p,q,3*i+3)==0)
                    imp.push_back(3*i+3);
            }
            else
            {
                imp.push_back(3*i+3);
                if(p==3*i+1 || query(p,q,3*i+1)==0)
                    imp.push_back(3*i+1);
                else imp.push_back(3*i+2);
            }
        }
        else
        {
            if(query(p,3*i+1,3*i+2)==1)
            {
                if(q!=3*i+3 && query(p,q,3*i+3)==0)
                    imp.push_back(3*i+3);
            }
            else
            {
                if(q!=3*i+1 && query(p,q,3*i+1)==0)
                    imp.push_back(3*i+1);
                else imp.push_back(3*i+2);
            }
        }
    }
    answer(imp);
    return 0;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}