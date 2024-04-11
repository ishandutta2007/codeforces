#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int s[MAXN];
int min(int x,int y)
{
    return x<y?x:y;
}
int gcd(int x,int y)
{
    return y==0?x:gcd(y,x%y);
}
struct node
{
    int left,right,mid,minicnt,minimum,gcdmum;
}t[MAXN<<2];
void Build(int left,int right,int num)
{
    int mid=left+((right-left)>>1);
    t[num].left=left;
    t[num].right=right;
    t[num].mid=mid;
    if(right-left==1){
        t[num].minicnt=1;
        t[num].minimum=s[left];
        t[num].gcdmum=s[left];
    }
    else{
        Build(left,mid,num<<1);
        Build(mid,right,num<<1|1);
        if(t[num<<1].minimum==t[num<<1|1].minimum){
            t[num].minicnt=t[num<<1].minicnt+t[num<<1|1].minicnt;
        }
        else if(t[num<<1].minimum<t[num<<1|1].minimum){
            t[num].minicnt=t[num<<1].minicnt;
        }
        else{
            t[num].minicnt=t[num<<1|1].minicnt;
        }
        t[num].minimum=min(t[num<<1].minimum,t[num<<1|1].minimum);
        t[num].gcdmum=gcd(t[num<<1].gcdmum,t[num<<1|1].gcdmum);
    }
}
int Query_Min(int left,int right,int num)
{
    if(left==t[num].left&&right==t[num].right)
        return t[num].minimum;
    if(right<=t[num].mid){
        return Query_Min(left,right,num<<1);
    }
    else if(left>=t[num].mid){
        return Query_Min(left,right,num<<1|1);
    }
    else{
        return min(Query_Min(left,t[num].mid,num<<1),
                   Query_Min(t[num].mid,right,num<<1|1));
    }
}
int Query_Gcd(int left,int right,int num)
{
    if(left==t[num].left&&right==t[num].right)
        return t[num].gcdmum;
    if(right<=t[num].mid){
        return Query_Gcd(left,right,num<<1);
    }
    else if(left>=t[num].mid){
        return Query_Gcd(left,right,num<<1|1);
    }
    else{
        return gcd(Query_Gcd(left,t[num].mid,num<<1),
                   Query_Gcd(t[num].mid,right,num<<1|1));
    }
}
int Query_Cnt(int left,int right,int num)
{
    if(left==t[num].left&&right==t[num].right)
        return t[num].minicnt;
    if(right<=t[num].mid){
        return Query_Cnt(left,right,num<<1);
    }
    else if(left>=t[num].mid){
        return Query_Cnt(left,right,num<<1|1);
    }
    else{
        int lmin=Query_Min(left,t[num].mid,num<<1);
        int rmin=Query_Min(t[num].mid,right,num<<1|1);
        if(lmin==rmin){
            return Query_Cnt(left,t[num].mid,num<<1)
                    +Query_Cnt(t[num].mid,right,num<<1|1);
        }
        else if(lmin<rmin){
            return Query_Cnt(left,t[num].mid,num<<1);
        }
        else{
            return Query_Cnt(t[num].mid,right,num<<1|1);
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&s[i]);
    Build(1,n+1,1);
    int q,l,r;
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&l,&r);
        if(Query_Min(l,r+1,1)==Query_Gcd(l,r+1,1)){
            printf("%d\n",r-l+1-Query_Cnt(l,r+1,1));
        }
        else printf("%d\n",r-l+1);
    }
    return 0;
}