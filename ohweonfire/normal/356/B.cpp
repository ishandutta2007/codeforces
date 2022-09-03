#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
const int maxn=(int)1e6+5;
int cnt[maxn][26];
int main()
{
    ll n,m;
    cin>>n>>m;
    string x,y;
    cin>>x>>y;
    int gcd=__gcd(x.size(),y.size());
    ll ans=0;
    for(int i=0;i<y.size();i++)cnt[i%gcd][y[i]-'a']++;
    for(int i=0;i<x.size();i++)ans+=(n*gcd/y.size()*cnt[i%gcd][x[i]-'a']);
    cout<<(ll)(n*x.size()-ans);
    return 0;
}