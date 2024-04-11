// Credit to robs77 for this template
/***********HEADER***************/
#include <iostream>
#include <bitset>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <set>
#include <queue>
#include <map>
#include <cstdlib>
#include <iomanip>
/***********MACROS***************/

#define ll  int64_t 
#define LL long long
#define fri(l,k) for (i=l;i<=k;i++)
#define frj(l,k) for (j=l;j>=k;j--)
#define fij(a,b,l,k) for(i=a;i<=b;i++) for(j=l;j<=k;j++)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define endl "\n"
#define pb push_back
#define _1 first
#define _2 second
#define mxsz 1000000007
#define mxval 1e9 + 7
#define grt [](auto x,auto y){return x>y;}
#define pii pair<int,int>
#define fi first 
#define se second 
 
/*********VARIABLE****************/
using namespace std;
typedef pair<int,int> ii;
/******************************/
ll n,i,v[500005],sum,pozst[500005],pozsf[500005],sum1,q,q1,st,dr,mij,sol,sol1;
/*********FUNCTIONS**************/

 

/***********MAIN**************/
 
signed main(){
   ios_base :: sync_with_stdio(false);
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    if(n<3)
    {
        cout<<"0";
    }
    else
    {
        if (sum%3==0)
        {
            sum=sum/3;
        }
        else
        {
            cout<<"0";
            return 0;
        }
        sum1=0;
        for (i=1;i<=n;i++)
        {
            sum1+=v[i];
            if (sum1==sum)
            {
                pozst[++q]=i;
            }
        }
        sum1=0;
        for (i=n;i>=1;i--)
        {
            sum1+=v[i];
            if (sum1==sum)
            {
                pozsf[++q1]=i;
            }
        }
        sort (pozsf+1,pozsf+q1+1);
        for (i=1;i<=q;i++)
        {
            st=1;
            dr=q1;
            sol=dr+1;
            while (st<=dr)
            {
                mij=(st+dr)/2;
                if (pozsf[mij]>pozst[i])
                {
                    sol=mij;
                    dr=mij-1;
                }
                else
                {
                    st=mij+1;
                }
            }
            if (pozsf[sol]==pozst[i]+1)
            {
                sol++;
            }
            sol1+=(q1-sol+1);
        }
        cout<<sol1;
    }
}
 
//