#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 

#define all(x) x.begin(), x.end()
#define tr(x,it) for(auto it = x.begin();it!=x.end();++it)
#define sz(a) int((a).size()) 
#define pb push_back 
#define mp make_pair
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)


int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int w,m;
    cin>>w>>m;
    if(w==2){cout<<"YES";return 0;}
    bool flag=1;

    int carry=0;
    while(1)
    {
        if(m==0&&carry==0)break;
        if(m==0&&carry==1){break;}
        int x=m%w;x+=carry;
      carry=x/w;x%=w;
        if(x==0||x==1){;}
        else if(x==w-1){carry+=1;}
        else {flag=0;break;}
        //if(!(x==1||x==0||x==w-1)){flag=0;break;}
        m/=w;
        
    }
    if(flag)cout<<"YES";else cout<<"NO";
    return 0;
}