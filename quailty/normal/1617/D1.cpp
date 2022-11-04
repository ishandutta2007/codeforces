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
    int mask=0; // 4 queries
    mask|=1<<query(3*x+1,3*y+1,3*x+2);
    mask|=1<<query(3*x+1,3*y+1,3*x+3);
    mask|=1<<query(3*x+1,3*y+1,3*y+2);
    mask|=1<<query(3*x+1,3*y+1,3*y+3);
    int p=3*x+1+(mask==2),q=3*y+1+(mask==1),pp=0,qq=0;
    vector<int> imp;
    for(int i=1;i<=n;i++)
    {
        if(i==p || i==q)continue;
        if(query(p,q,i)==0)imp.push_back(i),pp=i;
        else qq=i;
    }
    assert(pp && qq);
    if(query(pp,qq,p)==0)imp.push_back(p);
    else imp.push_back(q);
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