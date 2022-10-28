#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000007


#define debug
#ifndef debug
  #define endl "\n"
#endif
#ifdef debug
  #define pr(x)                  cerr << #x << ": " << x << endl;
  #define pr2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
  #define pr3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
  #define pr4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
  #define pr5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
  #define pr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
  #define prc(a) for(auto it: a) cerr<<(it)<<" "; cerr<<endl
  #define pra(a,n) for(int i=0; i<(n); i++) cerr<<((a)[i])<<" "; cerr<<endl
  #define prdd(a,r,c) for(int i=0;i<(r);i++) { for(int j = 0;j<(c);j++) cerr<<a[i][j]<<" "; cerr<<endl; } cerr<<endl;

#else
  #define pr(x)
  #define pr2(x, y)
  #define pr3(x, y, z)
  #define pr4(a, b, c, d)
  #define pr5(a, b, c, d, e)
  #define pr6(a, b, c, d, e, f)
  #define tr(c,it)
  #define prc(a)
  #define pra(a,n)
  #define prdd(a, r, c)
#endif

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size()) 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define rz resize
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}

const int N = 1e5;

int main()
{
  // boost;
  string s;cin>>s;
  string t = s;
  pair<int,int> x ={2,3};
  // string s = "11";
  int n = s.length();
  int z = count(all(s),'0');
  int o = count(all(s),'1');
  int q = count(all(s),'?');
  if(n==2)
  {
    if(q==0){cout<<s;return 0;}
    else if(q==1)
    {
      if(s[0]=='?'){s[0]='0';cout<<s<<"\n";s[0]='1';cout<<s;return 0;}
      s[1]='0';cout<<s<<"\n";s[1]='1';cout<<s;return 0;
    }
    cout<<"00\n01\n10\n11";return 0;
  }
  //00
  {
    if(o<=(n-1)/2)
      cout<<"00\n";
  }
  //01
  {
    NFOR(i,n-1,0)
    {
      if(s[i]=='0')break;
      if(s[i]=='?')s[i]='1',o++,q--;
      if(o<=(n-1)/2+1 and z<=(n-2)/2+1 and o+z+q==(n-1)/2+(n-2)/2+2)
        {cout<<"01\n";break;}
    }
    
  }
  //10
  {
    s=t;
    z = count(all(s),'0');
    o = count(all(s),'1');
    q = count(all(s),'?');

    NFOR(i,n-1,0)
    {
      if(s[i]=='1')break;
      if(s[i]=='?')s[i]='0',z++,q--;
      if(o<=(n-1)/2+1 and z<=(n-2)/2+1 and o+z+q==(n-1)/2+(n-2)/2+2)
        {cout<<"10\n";break;}
    }
  }
  //11
  {
    s=t;
    z = count(all(s),'0');
    if(z<=(n-2)/2)
      cout<<"11\n";
  }
  return 0;
}