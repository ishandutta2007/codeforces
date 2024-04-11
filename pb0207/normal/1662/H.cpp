#include<bits/stdc++.h>
using namespace std;

int T,n,m;

vector<int>can;

void get(int x)
{
    for(int i=1;i*i<=x;i++)
        if(x%i==0)
        {
            can.push_back(i);
            if(i*i!=x)
                can.push_back(x/i);
        }
}

vector<int>ans;

bool chk(int x)
{
    //---
    int t=n%x;
    if(t==0||t==1)
    {
        int ne=m-(t==0);
        t=ne%x;
        if(t==0||t==1)
        {
            int ne=n-(t==0);
            t=ne%x;
            if(t==0||t==1)
            {
                int ne=m-(t==0);
                t=ne%x;
                if(t==1)
                    return 1;
            }   
        }   
    }
    t=m%x;
    if(t==0||t==1)
    {
        int ne=n-(t==0);
        t=ne%x;
        if(t==0||t==1)
        {
            int ne=m-(t==0);
            t=ne%x;
            if(t==0||t==1)
            {
                int ne=n-(t==0);
                t=ne%x;
                if(t==1)
                    return 1;
            }   
        }   
    }
    return 0;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        get(n),get(n-1),get(n-2);
        get(m),get(m-1),get(m-2);
        sort(can.begin(),can.end());
        can.resize(unique(can.begin(),can.end())-can.begin());
        ans.clear();
        ans.push_back(1);
        for(auto x:can)
            if(chk(x))
                ans.push_back(x);
        printf("%d ",ans.size());
        for(int i=0;i<ans.size();i++)
            printf("%d%c",ans[i]," \n"[i+1==ans.size()]);
    }
}