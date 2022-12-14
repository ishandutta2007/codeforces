#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <typeinfo>
#include <locale>
#include <iterator>
#include <valarray>
#include <complex>
using namespace std;
#define LL long long
int seg[32][400001],upd[32][400001];
void update(int idx,int bi,int st,int ed)
{
    if(upd[bi][idx]%2==0)
    {
        upd[bi][idx]=0;
        return;
    }
    int mid=(st+ed)/2;
    seg[bi][idx*2+1]=(mid-st+1)-seg[bi][idx*2+1];
    seg[bi][idx*2+2]=(ed-mid)-seg[bi][idx*2+2];
    upd[bi][idx*2+1]++;
    upd[bi][idx*2+2]++;
    upd[bi][idx]=0;
}
void insert(int idx,int bi,int s,int e,int st,int ed)
{
    if(upd[bi][idx] && st!=ed)update(idx,bi,st,ed);
    if(s==st && e==ed)
    {
        seg[bi][idx]=(ed-st+1)-seg[bi][idx];
        if(st!=ed)upd[bi][idx]++;
        return;
    }
    int mid=(st+ed)/2;
    if(e<=mid)insert(idx*2+1,bi,s,e,st,mid);
    else if(s>mid)insert(idx*2+2,bi,s,e,mid+1,ed);
    else
    {
        insert(idx*2+1,bi,s,mid,st,mid);
        insert(idx*2+2,bi,mid+1,e,mid+1,ed);
    }
    seg[bi][idx]=seg[bi][idx*2+1]+seg[bi][idx*2+2];
}
int query(int idx,int bi,int s,int e,int st,int ed)
{
    //cout<<seg[bi][idx]<<" "<<upd[bi][idx]<<endl;
    if(upd[bi][idx]>0 && st!=ed)update(idx,bi,st,ed);
    if(s==st && e==ed)return seg[bi][idx];
    int mid=(st+ed)/2;
    if(e<=mid)return query(idx*2+1,bi,s,e,st,mid);
    else if(s>mid)return query(idx*2+2,bi,s,e,mid+1,ed);
    else
    {
        return query(idx*2+1,bi,s,mid,st,mid)+query(idx*2+2,bi,mid+1,e,mid+1,ed);
    }
}
int main()
{
    //freopen("a.out","w",stdout);
    int a,b,c,d,e,f,g,h,x,y,z;
    scanf("%d",&a);
    for(x=0;x<a;x++)
    {
        scanf("%d",&b);
        for(y=0;y<30;y++)
        {
            if((b& (1<<y))>0)insert(0,y,x,x,0,a-1);
        }
    }
    scanf("%d",&b);
    for(x=0;x<b;x++)
    {
        scanf("%d",&c);
        if(c==1)
        {
            scanf("%d %d",&d,&e);
            LL p=0;
            for(y=0;y<30;y++){p+=(LL)query(0,y,d-1,e-1,0,a-1)*(LL)(1<<y);}
            cout<<p<<endl;
        }
        else
        {
            scanf("%d %d %d",&d,&e,&f);
            for(y=0;y<30;y++)
            {
                if((f& (1<<y))>0)insert(0,y,d-1,e-1,0,a-1);
            }
        }
    }

}