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
#define vsort(v) sort(v.begin(),v.end())

set<int >ss[300001];
int st[300001],ed[300001];
vector<int>vc[300001],vr[300001];
vector<int>scc[300001];
int on[300001];

void dfs1(int id,int ct)
{
    st[id]=ct;
    int a,b,c,d,x,y,z;
    for(x=0;x<vc[id].size();x++)
    {
        if(st[vc[id][x]]!=0)continue;
        dfs1(vc[id][x],ct+1);
        ct=ed[vc[id][x]];
    }
    ed[id]=ct+1;
}
int get[300001];
pair<int,int>vp[300001];
int vis[300001];
int k;
int dfs2(int id,int v)
{
    vis[id]=v;
    get[v]=id;
    int a,b,c,x;
    for(x=0;x<vr[id].size();x++)
    {
        if(vis[vr[id][x]]!=0)
        {
            c=vis[vr[id][x]];
            if(v-c>=k)
            {
                cout<<v-c+1<<endl;
                for(b=vis[vr[id][x]];b<=v;b++)
                {
                    if(b!=vis[vr[id][x]])cout<<" ";
                    cout<<get[b];
                }
                cout<<endl;
                return 1;
            }
        }
        else
        {
            int p=dfs2(vr[id][x],v+1);
            if(p==1)return 1;
        }
    }
    return 0;
}

main()
{
    int a,b,c,d,e,f,g,h,t,ct,x,y,z;
        cin>>a>>b>>k;
        //here the loop starts
        for(x=0;x<b;x++)
        {
            cin>>e>>f;
            vc[e].push_back(f);
            vc[f].push_back(e);
            vr[e].push_back(f);
            vr[f].push_back(e);
        }
        for(x=1;x<=a;x++)
        {
            if(vis[x]==0)
            {
                d=dfs2(x,1);
                if(d==1)break;
            }
        }

}