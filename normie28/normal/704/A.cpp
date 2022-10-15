// Thanks to robs77 for this template
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
#define int long long 
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

set<int>s,notf[300005];
int mp[300005];
 
/*********FUNCTIONS**************/

/***********MAIN**************/

signed main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n,q,nf = 0,i,type,x,t,cnt;
    cin>>n>>q;
    while(q--){
        cin>>type>>x;
        if(type == 1){
            nf++;
            notf[x].insert(nf);
            s.insert(nf);
            mp[nf] = x;
        }
        else if(type == 2){
            for(auto it = notf[x].begin();it!=notf[x].end();it++){
                s.erase(s.find(*it));
            }
            notf[x].clear();
        }
        else{
            cnt = 0;
            for(auto it = s.begin();it!=s.end();it++){
                if(*it>x)break;
                cnt++;
            }
            while(cnt){
                auto it = s.begin();
                x = *it;
                notf[mp[x]].erase(notf[mp[x]].find(x));
                s.erase(it);
                cnt--;
            }
        }
        cout<<(int)s.size()<<'\n';
    }
}