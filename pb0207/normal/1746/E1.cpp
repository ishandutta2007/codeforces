#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n;

int qry(vector<int>v)
{
    printf("? %d ",(int)v.size());
    for(int i=0;i<v.size();i++)
        printf("%d%c",v[i]," \n"[i+1==v.size()]);
    fflush(stdout);
    char s[10];
    scanf("%s",s);
    return s[0]=='Y';
}

int gs(int x)
{
    printf("! %d\n",x);
    fflush(stdout);
    char s[10];
    scanf("%s",s);
    return s[1]==')';
}

vector<int>add(vector<int>a,vector<int>b)
{
    for(auto x:b)
        a.push_back(x);
    return a;
}

void solve(vector<int>v)
{
    if(v.size()==1)
    {
        gs(v[0]);
        return;
    }
    if(v.size()==2)
    {
        int a=gs(v[0]);
        if(!a)
            gs(v[1]);
        return;
    }
    if(v.size()==3)
    {
        int a=qry({v[0]});
        if(a)
        {
            int b=qry({v[1]});
            int p=gs(v[0]);
            if(p)
                return;
            if(b)
                gs(v[1]);
            else
                gs(v[2]);
        }
        else
        {
            int b=qry({v[0]});
            if(!b)
            {
                int c=gs(v[1]);
                if(!c)
                    gs(v[2]);
                return;
            }
            else
            {
                int c=qry({v[1]});
                int d=gs(v[0]);
                if(!d)
                {
                    if(c)
                        gs(v[1]);
                    else
                        gs(v[2]);
                }
                return;
            }
        }
    }
    vector<int>nw[4];
    for(int i=0;i<v.size();i+=4)
    {
        for(int j=0;j<4;j++)
            if(i+j<v.size())
                nw[j].push_back(v[i+j]);
    }
    int a=qry(add(nw[0],nw[1]));
    int b=qry(add(nw[0],nw[2]));
    if(a&&b)
        solve(add(add(nw[0],nw[1]),nw[2]));
    if(a&&!b)
        solve(add(add(nw[0],nw[1]),nw[3]));
    if(b&&!a)
        solve(add(add(nw[0],nw[2]),nw[3]));
    if(!a&&!b)
        solve(add(add(nw[1],nw[2]),nw[3]));
}

int main()
{
    scanf("%d",&n);
    vector<int>v;
    for(int i=1;i<=n;i++)
        v.push_back(i);
    solve(v);
}