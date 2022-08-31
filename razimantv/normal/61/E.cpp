# include <cstdio>
# include <algorithm>
# include <iostream>
# include <cstring>

using namespace std;

struct two
{
    int h,id;
}array[1000000];

bool cmp1(two t1,two t2)
{
    return t1.h<t2.h;
}

bool cmp2(two t1,two t2)
{
    return t1.id<t2.id;
}

int segtree[1<<21];

void addbad(int node)
{
    while(node)
    {
        segtree[node]++;
        node>>=1;
    }
}

int countbad(int node,int l,int r,int x,int y)
{
    if(l==x&&r==y)return segtree[node];
    int m=(l+r)>>1;
    if(y<=m)return countbad(node<<1,l,m,x,y);
    else if(x>m)return countbad((node<<1)|1,m+1,r,x,y);
    else return countbad(node<<1,l,m,x,m)+countbad((node<<1)|1,m+1,r,m+1,y);
}

int main()
{
    int N;
    scanf("%d",&N);
    
    for(int i=0;i<N;i++)
    {
        array[i].id=i;
        scanf("%d",&array[i].h);
    }
    
    sort(array,array+N,cmp1);
    
    for(int i=0;i<N;i++)
        array[i].h=i;
    
    sort(array,array+N,cmp2);
    
    memset(segtree,0,1<<23);
    
    int bad;
    long long ret=0ll;
    for(int i=0;i<N;i++)
    {
        bad=countbad(1,0,(1<<20)-1,array[i].h+1,N);
        addbad((1<<20)+array[i].h);
        ret+=bad*(long long)(array[i].h+bad-i);
    }
    
    cout<<ret<<"\n";
    
    return 0;
}