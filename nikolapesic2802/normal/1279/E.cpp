#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

const int N=50+1;
const ll lim=(ll)(1e18)+5,oo=3e18;
vector<ll> fact(3,1),dp(N,-1);
ll mul(ll a,ll b){
    if(lim/a<=b)
        return oo;
    a*=b;
    if(a>=lim)
        return oo;
    return a;
}
ll add(ll a,ll b){
    a+=b;
    if(a>=lim)
        return oo;
    return a;
}
ll calc(int a){
    if(a==0)
        return 1;
    if(dp[a]!=-1)
        return dp[a];
    dp[a]=0;
    for(int i=1;i<=a;i++)
        dp[a]=add(dp[a],mul(calc(a-i),fact[i]));
    return dp[a];
}
vector<int> ans;
int chainBase[N],baseofChain[N];
void dodaj(int offset,int vel,ll k){
    ans.pb(vel+offset);
    for(int i=0;i<vel;i++)
        chainBase[i]=baseofChain[i]=i;
    vector<bool> taken(vel);
    for(int i=1;i<vel;i++)
        for(int j=0;j<vel-1;j++)
            if(!taken[j]&&chainBase[i]!=j){
                if(k<=fact[vel-i]){
                    ans.pb(offset+j+1);
                    baseofChain[chainBase[i]]=baseofChain[j];
                    chainBase[baseofChain[j]]=chainBase[i];
                    taken[j]=1;
                    break;
                }
                k-=fact[vel-i];
            }
}
int n;
void gen(int a,ll k){
    if(a==0)
        return;
    for(int i=1;i<=a;i++){
        ll drugo=calc(a-i);
        ll imam=mul(drugo,fact[i]);
        if(imam>=k){
            ll koliko=(k-1)/drugo;
            dodaj(n-a,i,koliko+1);
            k-=koliko*drugo;
            gen(a-i,k);
            return;
        }
        k-=imam;
    }
}
int main()
{
    for(int i=1;i<N;i++)
        fact.pb(mul(fact.back(),i));
    int t;
    scanf("%i",&t);
    while(t--){
        ll k;
        scanf("%i %lld",&n,&k);
        if(calc(n)<k){
            printf("-1\n");
            continue;
        }
        ans.clear();
        gen(n,k);
        for(auto p:ans)
            printf("%i ",p);
        printf("\n");
    }
    return 0;
}