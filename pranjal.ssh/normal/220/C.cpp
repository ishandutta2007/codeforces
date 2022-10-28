#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000009

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size()) 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define rz resize
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
const int N = 1e5+10;
int a[N],b[N]; 
int pa[N],pb[N];

int main()
{
  boost;
  int nn;cin>>nn;
  FOR(i,1,nn)cin>>b[i],pb[b[i]]=i;
  FOR(i,1,nn)cin>>a[i],pa[a[i]]=i;
  multiset<int> p,n;
  int oa=0,ob=0;
  FOR(i,1,nn)
  i-pb[a[i]]>=0?p.insert(i-pb[a[i]]):n.insert(pb[a[i]]-i);
  int ans=nn;
  if(!p.empty())ans=min(ans,*p.begin());
  if(!n.empty())ans=min(ans,*n.begin());
  cout<<ans<<"\n";
  vi yo;
  NFOR(i,nn,2){
    oa++,ob--;
    p.erase(p.find(nn+1-pb[a[i]]-oa));
    1-pb[a[i]]>=0?p.insert(1-pb[a[i]]-oa):n.insert(pb[a[i]]-1-ob);
    set<int>::iterator it;
    while(!n.empty() and *n.begin()+ob<=0)
      p.insert(abs(*n.begin()+ob)-oa),n.erase(n.begin());
    ans=nn;
    if(!p.empty())ans=min(ans,*p.begin()+oa);
    if(!n.empty())ans=min(ans,*n.begin()+ob);
    yo.push_back(ans);
  }
  reverse(all(yo));
  for(int i:yo)cout<<i<<"\n";
  return 0;
}