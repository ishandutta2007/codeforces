#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;


ll n,i,j, m, q;
vector <vector <ll>> f;
vector <ll> val;
bool viv=false;

void row(ll num)
{
for (ll i=0; i<m-1; i++)
  swap(f[num][i], f[num][i+1]);
}

void col(ll num)
{
for (ll i=0; i<n-1; i++)
  swap(f[i][num], f[i+1][num]);
}

void work()
{
ll ty;
cin>>ty;
if (ty==1)
  {
  ll num;
  cin>>num;
  num--;
  row(num);
  }
if (ty==2)
  {
  ll num;
  cin>>num;
  num--;
  col(num);
  }
if (ty==3)
  {
  ll x, y, v;
  cin>>x>>y>>v;
  x--, y--;
  val[f[x][y]]=v;
  }
}

void write()
{
for (ll i=0; i<n; i++)
  {
  for (ll j=0; j<m; j++)
    cout<<val[i*m+j]<<' ';
  cout<<endl;
  }
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m>>q;
for (ll i=0; i<n; i++)
  {
  f.push_back({});
  for (ll j=0; j<m; j++)
    f[i].push_back(i*m+j);
  }
val.resize(n*m, mod);
while (q--)
  work();

for (auto &i:val)
  if (i==mod)
    i=239;

write();

    return 0;
}