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
#define PI 2.0*acos(0.0)
#define linf (1ll<<60)-1
#define all(v) (v.begin(),v.end())
#define set0(ar) memset(ar,0,sizeof ar)
#define vsort(v) sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)



template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (LL)((t*t)%M);}
    return ((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}


LL ar1[100001],ar2[100001];
LL dp[101][100001];
LL vv[100001];
LL M[101][100001];
LL B[101][100001];
LL bad(LL l1,LL l2,LL l3,LL l)
{
    return (B[l][l3]-B[l][l1])*(M[l][l1]-M[l][l2])>=(B[l][l2]-B[l][l1])*(M[l][l1]-M[l][l3]);
}
LL cnt;
void insert_line(LL m,LL b,LL l)
{
    M[l][cnt]=m;
    B[l][cnt++]=b;
    while (cnt>=3 && bad(cnt-3,cnt-2,cnt-1,l)>0)
    {
        swap(M[l][cnt-1],M[l][cnt-2]);
        swap(B[l][cnt-1],B[l][cnt-2]);
        cnt--;
    }
}
LL p;
LL query(LL x,LL l)
{
    if(p>=cnt)p=cnt-1;
    while(p<cnt-1 && M[l][p+1]*x+B[l][p+1]<=M[l][p]*x+B[l][p])p++;
    return M[l][p]*x+B[l][p];
}
main()
{
    LL a,b,c,d,e,f,g,h,x,y,z;
    cin>>a>>b>>c;
    for(x=2;x<=a;x++){
        cin>>ar1[x];
        ar1[x]+=ar1[x-1];
    }
    for(x=1;x<=b;x++)
    {
        cin>>d>>e;
        ar2[x]=e-ar1[d];
    }
    sort(ar2+1,ar2+b+1);
    for(x=1;x<=b;x++)ar2[x]=ar2[b]-ar2[x];
    sort(ar2+1,ar2+b+1);
    for(x=1;x<=b;x++){
        ar2[x]+=ar2[x-1];
        dp[1][x]=ar2[x];
        if(x<b){
            vv[x]=dp[1][x]+x*ar2[x+1]-ar2[x];
            //cout<<vv[1][x]<<" "<<ar2[x+1]<<" "<<ar2[x]<<endl;
        }
    }
    for(x=2;x<=c;x++)
    {
        cnt=0;
        p=0;
        insert_line(ar2[x]-ar2[x-1],vv[x-1],x-1);
        for(y=x;y<=b;y++)
        {
            dp[x][y]=ar2[y]+query(-y,x-1);
            //cout<<dp[x][y]<<endl;
            if(y<b){
                insert_line(ar2[y+1]-ar2[y],vv[y],x-1);
                vv[y]=dp[x][y]+y*(ar2[y+1]-ar2[y])-ar2[y];
            }
        }
    }
    cout<<dp[c][b]<<endl;

}
/*
0
0
0
8 e=ar2[y];
            for(z=d;z<y;z++)
            {
                g=y-z;
                g*=(ar2[z+1]-ar2[z]);
                g+=ar2[z];
                if(e-g+dp[x-1][z]>f)continue;
                else {
                    f=e-g+dp[x-1][z];
                    d=z;
                }
            }
9
10
*/