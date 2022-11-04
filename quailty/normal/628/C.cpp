#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
char s[MAXN],t[MAXN];
int a[MAXN];
pair<int,int>p[MAXN];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    for(int i=0;i<n;i++)
        a[i]=s[i]-'a';
    for(int i=0;i<n;i++)
        p[i]=make_pair(max(a[i],25-a[i]),i);
    sort(p,p+n,greater<pair<int,int> >());
    for(int i=0;i<n;i++)
    {
        if(k>p[i].first)
        {
            if(a[p[i].second]-p[i].first>=0)t[p[i].second]='a';
            else t[p[i].second]='z';
            k-=p[i].first;
        }
        else
        {
            if(a[p[i].second]-k>=0)t[p[i].second]='a'+a[p[i].second]-k;
            else t[p[i].second]='a'+a[p[i].second]+k;
            k=0;
        }
    }
    if(k>0)printf("-1");
    else printf("%s",t);
    return 0;
}