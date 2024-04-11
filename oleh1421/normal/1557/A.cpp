#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll>pairll;
typedef pair<ll,pairll>pairlll;
typedef pair<pairll,pairll>pairllll;
typedef long double ld;
typedef pair<ll,string>pairls;

#define INF 1000000000
#define MOD 1000000007
#define pb push_back
#define fr first
#define sc second
#define endl '\n'

ll d,r,res,k;
ll t,n;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        r=0;
        res=-INF;
        for(int i=1;i<=n;i++){
            cin>>d;
            r+=d;
            if(res<d)res=d;
        }
        cout<<fixed<<setprecision(10)<<res+(r-res)/ld(n-1)<<endl;
    }


}