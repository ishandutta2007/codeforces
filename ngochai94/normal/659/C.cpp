#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

int n,m,tot;
set<int> s;
vector<int> ans;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>tot;
    while(n--)
    {
        cin>>m;
        s.insert(m);
    }
    int cur=0;
    while(++cur)
    {
        if(!s.count(cur))
        {
            tot-=cur;
            if(tot>=0) ans.pb(cur);
            if(tot<=0) break;
        }
    }
    cout<<ans.size()<<endl;
    for(auto i:ans) cout<<i<<' ';
}