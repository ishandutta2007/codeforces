/********************************************************************************\
   |--\        ---       /\        |-----------| -----       /-------|           |
   |   \        |       /  \       |               |        /                    |
   |    \       |      /    \      |               |       |                     |
   |     \      |     /      \     |               |        \---\                |
   |      \     |    / ------ \    |-------|       |             \---\           |
   |       \    |   /          \   |               |                  |          |
   |        \   |  /            \  |               |                  /          |
  ---        \------            ------           -----     |---------/           |
                                                                                 |
                          _                                                      |
  **copyrighted by nfssdq(R) :) (:                                               |
                          ^                                                      |
    codeforces = nfssdq                                                          |
    topcoder = nafis007                                                          |
    uva = nfssdq                                                                 |
    spoj = nfssdq                                                                |
    usaco = nfssdq1                                                              |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                           |
    IIT,Jahangirnagar University(41)                                             |
    Sorry for badly written code.  :(                                            |
                                                                                 |
*********************************************************************************/


#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <locale>
#include <string>
#include <vector>
#include <cassert>
#include <climits>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <iterator>
#include <typeinfo>
#include <valarray>
#include <algorithm>
#include <functional>

using namespace std;

#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define LL long long
#define inf INT_MAX/2
#define mod 1000000007
#define linf (1ll<<63)-1
#define all(v) (v.begin(),v.end())
#define set0(ar) memset(ar,0,sizeof ar)
#define vsort(v) sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)
#define PI 3.141592653589793238462643383279502884197169399375


template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){T t=bigmod(p,e/2,M);return (t*t)%M;}
    return (bigmod(p,e-1,M)*p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}


struct node
{
    int st,ed,cnt;
    LL ls,rs,sum;
    node *l,*r;
    node(LL s,LL e)
    {
        st=s;ed=e;
        ls=rs=0;
        cnt=sum=0;
        l=r=NULL;
    }
};


void insert(node *ob,int p,int v)
{
    if(ob->st==ob->ed)
    {
        if(v==1)
        {
            ob->cnt++;
            ob->ls=1;
            ob->rs=1;
        }
        else
        {
            ob->cnt--;
            ob->ls=0;
            ob->rs=0;
        }
        return;
    }
    int mid=((LL)ob->st+(LL)ob->ed)/2;
    if(ob->l==NULL)ob->l=new node(ob->st,mid);
    if(ob->r==NULL)ob->r=new node(mid+1,ob->ed);
    if(p<=mid)insert(ob->l,p,v);
    else insert(ob->r,p,v);
    if(v==1)
    {
        ob->ls+=(LL)(p-ob->st+1);
        ob->rs+=(LL)(ob->ed-p+1);
        ob->cnt++;
    }
    else
    {
        ob->ls-=(LL)(p-ob->st+1);
        ob->rs-=(LL)(ob->ed-p+1);
        ob->cnt--;
    }
    ob->sum=ob->l->sum+ob->r->sum+ob->l->cnt*ob->r->ls+ob->r->cnt*ob->l->rs;
}

LL nc;
LL sum;

LL query(node *ob,int s,int e )
{
    if(ob->st==s && ob->ed==e)
    {
        LL ret=ob->cnt*sum+nc*ob->ls+ob->sum;
        //cout<<s<<" "<<e<<" "<<ret<<" "<<ob->sum<<endl;
        sum+=nc*(e-s+1);
        nc+=ob->cnt;
        sum+=ob->rs;
        return ret;
    }
    int mid=((LL)ob->st+(LL)ob->ed)/2;
    if(ob->l==NULL)ob->l=new node(ob->st,mid);
    if(ob->r==NULL)ob->r=new node(mid+1,ob->ed);
    if(e<=mid)return query(ob->l,s,e);
    else if(s>mid)return query(ob->r,s,e);
    return query(ob->l,s,mid)+query(ob->r,mid+1,e);
}
LL ar[100001];
main()
{
    LL a,b,c,d,e,f,x,y,z;
    cin>>a;
    node *root=new node(0,2000000000);
    for(x=1;x<=a;x++)
    {
        cin>>b;
        b+=1000000000;
        insert(root,b,1);
        ar[x]=b;
    }
    cin>>b;
    for(x=0;x<b;x++)
    {
        cin>>c>>d>>e;
        if(c==1)
        {
            insert(root,ar[d],0);
            ar[d]+=e;
            insert(root,ar[d],1);
        }
        else
        {
            sum=0;
            nc=0;
            d+=1000000000;
            e+=1000000000;
            f=query(root,d,e);
            f-=nc*(nc-1)/2;
            cout<<f<<endl;
        }
    }
}