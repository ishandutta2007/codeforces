#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;
set<pair<queue<int>,queue<int> > >s;
queue<int>q1,q2;
int main()
{
    int n,k1,k2;
    scanf("%d",&n);
    scanf("%d",&k1);
    int in;
    for(int i=1;i<=k1;i++)
    {
        scanf("%d",&in);
        q1.push(in);
    }
    scanf("%d",&k2);
    for(int i=1;i<=k2;i++)
    {
        scanf("%d",&in);
        q2.push(in);
    }
    int win=0,cnt=0;
    while(1)
    {
        if(s.find(make_pair(q1,q2))!=s.end())break;
        s.insert(make_pair(q1,q2));
        cnt++;
        if(q1.front()>q2.front())
        {
            q1.push(q2.front());
            q1.push(q1.front());
            q1.pop();
            q2.pop();
        }
        else
        {
            q2.push(q1.front());
            q2.push(q2.front());
            q1.pop();
            q2.pop();
        }
        if(q1.empty())
        {
            win=2;
            break;
        }
        if(q2.empty())
        {
            win=1;
            break;
        }
    }
    if(win)printf("%d %d\n",cnt,win);
    else printf("-1\n");
    return 0;
}