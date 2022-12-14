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

#define xx first
#define yy second
#define LL long long
int X[100001],Y[100001],ar[9];
pair<int,int>pp[100001];
int seg[2001][2001],segr[2001][2001];
int g,h;
int query(int lm,int cc,int hm)
{
    int a=0,b,c,d,e,f=0,x,y,z;
    for(x=0;x<=h;x++)
    {
        f+=g;
        if(f<=lm+1)
        {
            a+=upper_bound(seg[x],seg[x]+g,hm)-seg[x];
        }
        else
        {
            f-=g;
            //cout<<h<<" "<<f<<endl;
            for(y=0;y<=lm-f;y++)if(segr[x][y]<=hm)a++;
            break;
        }
    }
    //cout<<a<<" "<<cc<<" "<<hm<<" "<<lm<<endl;
    if(a==cc)return 1;
    return 0;
}
main()
{
    int a,b,c,d,e,f,x,y,z;
    int p,q,r,s;
    cin>>a;
    for(x=0;x<a;x++)
    {
        scanf("%d %d",&X[x],&Y[x]);
        pp[x].xx=X[x];
        pp[x].yy=Y[x];
    }
    for(x=0;x<9;x++)cin>>ar[x];
    sort(X,X+a);
    sort(Y,Y+a);
    sort(ar,ar+9);
    sort(pp,pp+a);
    g=sqrt(a);
    h=0;
    f=0;
    for(x=0;x<a;x++)
    {
        if(f==g)
        {
            f=0;
            sort(seg[h],seg[h]+g);
            h++;
        }
        seg[h][f]=pp[x].yy;
        segr[h][f]=pp[x].yy;
        f++;
    }
    sort(seg[h],seg[h]+f);
    //for(x=0;x<=h;x++)
    {
       // for(y=0;y<g;y++)cout<<seg[x][y]<<" ";
        //cout<<endl;
    }
    do
    {
        //for(x=0;x<9;x++)cout<<ar[x]<<" ";
        //cout<<endl;
        b=ar[0]+ar[3]+ar[6];
        if(Y[b-1]!=Y[b])p=Y[b-1];
        else continue;
        b+=ar[1]+ar[4]+ar[7];
        if(Y[b-1]!=Y[b])q=Y[b-1];
        else continue;
        b=ar[0]+ar[1]+ar[2];
        if(X[b-1]!=X[b])r=X[b-1];
        else continue;
        b+=ar[3]+ar[4]+ar[5];
        if(X[b-1]!=X[b])s=X[b-1];
        else continue;
        b=ar[0]+ar[1]+ar[2];
        c=ar[0];
        if(query(b-1,c,p)==0)continue;
        c+=ar[1];
        if(query(b-1,c,q)==0)continue;
        b+=ar[3]+ar[4]+ar[5];
        c=ar[0]+ar[3];
        if(query(b-1,c,p)==0)continue;
        c+=ar[1]+ar[4];
        if(query(b-1,c,q)==0)continue;
        b=a;
        c=ar[0]+ar[3]+ar[6];
        if(query(b-1,c,p)==0)continue;
        c+=ar[1]+ar[4]+ar[7];
        if(query(b-1,c,q)==0)continue;
        printf("%lf %lf\n%lf %lf\n",(double)r+0.5,(double)s+0.5,(double)p+0.5,(double)q+0.5);
        return 0;
    }while(next_permutation(ar,ar+9));
    cout<<-1<<endl;
}