#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN=100005;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    set<int>s;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        s.insert(a);
    }
    vector<int>v;
    for(int i=1;;i++)
        if(s.find(i)==s.end())
        {
            if(m>=i)v.push_back(i),m-=i;
            else break;
        }
    printf("%d\n",(int)v.size());
    for(int i=0;i<(int)v.size();i++)
        printf("%d ",v[i]);
    return 0;
}