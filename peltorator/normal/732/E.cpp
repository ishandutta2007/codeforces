#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
typedef pair<ll,ll> llll;
ll n,m,p[200005],ctrl[200005],ans,ANS;
ll ress[200005], resp[200005];
llll s[200005];
map <ll,ll> mp;
vector <ll> nen,ax[200005];
int main(){
    nen.push_back(1);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&p[i]),
        nen.push_back(p[i]),
        mp[p[i]] ++;
    sort(nen.begin(),nen.end());
    nen.resize(distance(nen.begin(),unique(nen.begin(),nen.end())));
    for(int i=1;i<=n;i++)   ax[lower_bound(nen.begin(),nen.end(),p[i]) - nen.begin() + 1] .push_back(i);
    for(int i=1;i<=m;i++)
        scanf("%lld",&s[i].fi),
        s[i].se = i;
    sort(s+1,s+m+1);
    for(int i=1;i<=m;i++){
        int tmp = s[i].fi, cnt = 0;
        bool ok1 = 0;
        while(tmp > 0){
            if (mp[tmp]){
                int hi = lower_bound(nen.begin(),nen.end(),tmp) - nen.begin() + 1;
                ANS ++, ans += cnt, mp[tmp] --, ress[s[i].se] = cnt, resp[ax[hi][ctrl[hi]]] = s[i].se, ctrl[hi] ++;
                break;
            }
            if (tmp % 2) tmp = tmp/2 + 1;
            else tmp = tmp/2;
            cnt ++;
            if (ok1) break;
            if (tmp == 1) ok1 = 1;
        }
    }
    printf("%lld %lld\n",ANS,ans);
    for(int i=1;i<=m;i++)
        printf("%lld ",ress[i]); printf("\n");
    for(int i=1;i<=n;i++)
        printf("%lld ",resp[i]);
}