#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
const int MAXN=200005;
int a[MAXN];
deque<pair<int,int> >s;
deque<int>q;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    {
        int t,r;
        scanf("%d%d",&t,&r);
        while(!s.empty() && r>=s.back().first)s.pop_back();
        s.push_back(make_pair(r,t));
    }
    s.push_back(make_pair(0,1));
    sort(a+1,a+s[0].first+1);
    for(int i=1;i<=s[0].first;i++)
        q.push_back(a[i]);
    bool rev;
    if(s[0].second==1)rev=0;
    else rev=1;
    int now=s[0].first;
    for(int i=1;i<(int)s.size();i++)
    {
        int d=s[i-1].first-s[i].first;
        while(d--)
        {
            if(rev)a[now--]=q.front(),q.pop_front();
            else a[now--]=q.back(),q.pop_back();
        }
        if(s[i].second==1)rev=0;
        else rev=1;
    }
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    return 0;
}