// Credit to robs77 for this template
/***********HEADER***************/
#include <iostream>
#include <bitset>
#include <iomanip>
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
/***********MACROS***************/
//#define int long long 
#define ll  long long 
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
#define mod 1000000007
#define inf 100000000
/*********VARIABLE****************/
using namespace std;
typedef pair<int,int> ii;
/******************************/

/*********FUNCTIONS**************/

/***********MAIN**************/

signed main(){ 
    vector <int> v,w;
    int n,a,max_,min_;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        w.push_back(a);
    }
    sort(w.begin(),w.end());
 
    for(int i=1;i<=3000000;i++)
    {
        v.push_back(i);
    }
    bool flag=0;
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<w.size();j++)
        {
            if(v[i]==w[j])
            {
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            cout<<v[i]<<endl;
            return 0;
        }
        else
        {
            flag = 0;
            continue;
        }
    }
    return 0;
}