#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
struct node
{
    ll k,y;
    int id;
    node(){}
    node(ll _k,ll _y,int _id):k(_k),y(_y),id(_id){}
    bool operator < (const node &t)const
    {
        return y==t.y ? k<t.k : y<t.y;
    }
}pl[100005],pr[100005];
int main()
{
    int n;
    scanf("%d",&n);
    ll l,r;
    scanf("%I64d%I64d",&l,&r);
    for(int i=0;i<n;i++)
    {
        ll k,b;
        scanf("%I64d%I64d",&k,&b);
        pl[i]=node(k,l*k+b,i);
        pr[i]=node(-k,r*k+b,i);
        //printf("%I64d %I64d %I64d %I64d\n",pl[i].k,pl[i].y,pr[i].k,pr[i].y);
    }
    sort(pl,pl+n);
    sort(pr,pr+n);
    bool isok=0;
    for(int i=0;i<n;i++)
        if(pl[i].id!=pr[i].id)
            isok=1;
    printf("%s\n",(isok ? "YES" : "NO"));
    return 0;
}