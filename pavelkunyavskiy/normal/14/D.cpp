#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define int64 long long
#define ld long double  
#define setval(a,v) memset(a,v,sizeof(a))
using namespace std;

vector<int> g[200];
int n;

bool used1[200];
bool used2[200];

int dest(int v,int to){
    if (v==to)
    {
        used1[v]=true;
        return 0;
    }
    int sz=g[v].size();
    used2[v]=true;
    for (int i=0;i<sz;i++)
        if (!used2[g[v][i]])
            {
                int tmp=dest(g[v][i],to);
                if (tmp!=-1)
                    {
                        used1[v]=true;
                        return tmp+1;
                    }
            }
    return -1;
}

int best;

int max_dest(int v){
    used1[v]=true;
    int b1=0,b2=0;
    int sz=g[v].size();
    for (int i=0;i<sz;i++)
        if (!used1[g[v][i]])
        {
            int tmp=max_dest(g[v][i]);
            if (b1<tmp)
                swap(b1,tmp);
            if (b2<tmp)
                swap(b2,tmp);
        }
    best=max(best,b1+b2);
    return b1+1;
}




int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d",&n);
    for (int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        --a,--b;
        g[b].pb(a);
        g[a].pb(b);
    }
    int ans=0;
    for (int v1=0;v1<n;v1++)
        for (int v2=0;v2<n;v2++){
            setval(used1,false);
            setval(used2,false);
            int tmp=dest(v1,v2);
            int tmp2=0;
            for (int i=0;i<n;i++)
                if (!used1[i])
                {
                    best=0;
                    max_dest(i);
                    tmp2=max(tmp2,best);
                }                   
            tmp*=tmp2;
            ans=max(ans,tmp);
        }
    printf("%d\n",ans);
  return 0;
}