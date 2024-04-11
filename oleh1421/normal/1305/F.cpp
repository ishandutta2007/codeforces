#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
///#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=200010;
mt19937 rng(time(NULL));
ll a[N];
bool used[2000010];
vector<ll>Primes;
vector<ll>p;
void fct(ll x){
    int d=0;
    while (p[d]*p[d]<=x){
        if (x%p[d]==0){
            Primes.push_back(p[d]);
            while (x%p[d]==0) x/=p[d];
        }
        d++;
    }
    if (x>1) Primes.push_back(x);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=2;i<=2000000;i++) used[i]=true;
    for (int i=2;i*i<=2000000;i++){
        if (used[i]){
            for (int j=i*i;j<=2000000;j+=i) used[j]=false;
        }
    }
    for (int i=2;i<=2000000;i++){
        if (used[i]) p.push_back(i);
    }
    for (int i=1;i<=20;i++){
        int x=rng()%n+1;
        fct(a[x]);
        fct(a[x]+1);
        if (a[x]>1) fct(a[x]-1);
    }
    Primes.push_back(2);
    ll minx=n;
    for (auto d:Primes){
        ll sum=0;
        for (int i=1;i<=n;i++){
            if (a[i]<d) sum+=d-a[i];
            else sum+=min(a[i]%d,d-a[i]%d);
        }
        minx=min(minx,sum);
    }
    cout<<minx;

    return 0;
}