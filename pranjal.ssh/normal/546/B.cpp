#include <bits/stdc++.h>
using namespace std;

#define INF 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

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
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    int a[n];
    FOR(i,0,n-1)cin>>a[i];
    sort(a,a+n);
    int ans=0;
    int mx=a[0];
    FOR(i,1,n-1)
    {
        if(a[i]>mx){mx=a[i];continue;}
        if(a[i]==mx){ans+=1;a[i]=mx+1;mx++;}
        if(a[i]<mx){ans+=(mx-a[i]);++ans;mx++;}
    }
    cout<<ans;
    return 0;
}