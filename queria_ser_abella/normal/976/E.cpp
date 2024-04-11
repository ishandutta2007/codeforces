#include <bits/stdc++.h>
#define maxn 300300
using namespace std;
#define pb push_back
#define pii pair<ll,ll>
#define pip pair<ll,pii>
#define debug 
#define ll long long
#define move ouehfri
#define left cjsbsoiyafg


struct mons {
    ll hp,dam;
    bool operator<(mons comp)const{
        return hp-dam > comp.hp-comp.dam;
    }
}

v[maxn];

main(){
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    for(int i=0;i<n;i++)
        scanf("%I64d%I64d",&v[i].hp,&v[i].dam);
    sort(v,v+n);
    ll sum = 0, sb = 0;
    for(int i=0;i<n;i++)
        sum += v[i].dam;
    for(int i=0;i<min(n,b);i++)
        sb += max(0ll,v[i].hp-v[i].dam);
    
    ll mul = (1<<a);
    ll novo = 0;
    if(b)
        novo = max(0ll,v[b-1].hp-v[b-1].dam);
    ll ans = sum + sb;
    debug("sum %lld sb %lld\n",sum,sb);
        
    for(int i=0;i<n;i++){
        if(i < b){
            ans = max(ans,sum + sb - max(v[i].hp,v[i].dam) + v[i].hp * mul);
        }
        else if(b){
            ans = max(ans,sum + sb - v[i].dam + v[i].hp * mul - novo);
        }
    }
    
    cout << ans << endl;
}