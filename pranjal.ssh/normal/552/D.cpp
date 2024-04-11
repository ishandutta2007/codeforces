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
#define MP make_pair
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)


map<pair<ii,ii>,ll > mp;
int x[2000];
int y[2000];
ll ans;
int main() 
{
    ans=0;
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n;cin>>n;
    ans=n*(n-1)*(n-2)/6;
    FOR(i,0,n-1)cin>>x[i]>>y[i];
    FOR(i,0,n-1)
    {
        FOR(j,i+1,n-1)
        {
            if(y[i]==y[j]) {mp[MP(MP(0,0),MP(y[i],y[i]))]++;continue;}
            else if(x[i]==x[j]){mp[MP(MP(0,1),(MP(x[i],x[i])))]++;continue;}
            int Y=(y[i]-y[j]);
            int X=(x[i]-x[j]);
            int K=y[i]*X-Y*x[i];
            int J=X;
            if(X*Y<0){X=abs(X);Y=abs(Y);int Z=__gcd(X,Y);X/=Z;Y/=Z;Y=-Y;}
            else {X=abs(X);Y=abs(Y);int Z=__gcd(X,Y);X/=Z;Y/=Z;}
            
            if(K==0){mp[MP(MP(Y,X),(MP(0,1)))]++;continue;}
            if(K*J<0){J=abs(J);K=abs(K);int Z=__gcd(J,K);J/=Z;K/=Z;K=-K;}
            else {J=abs(J);K=abs(K);int Z=__gcd(J,K);J/=Z;K/=Z;}
            mp[MP(MP(Y,X),MP(K,J))]++;
        }
    }
    tr(mp,it)
    {
        ll X=it->S;
        X=(1+sqrt(1+8*X))/2;
        ans-=X*(X-1)*(X-2)/6;
        
    }
    cout<<ans;
    return 0;
}