#include <bits/stdc++.h>
#define pii pair<int,int>
#define ppi pair<pii,int>
#define L first.first
#define R first.second
#define T second
#define pb push_back
#define maxn 200200
#define pit set<ppi> :: iterator
#define rit set<ppi> :: reverse_iterator
#define ll long long
#define debug
using namespace std;

vector<int> pos[maxn];
vector<pii> sw[maxn];

ll sum = 0;
set<ppi> S;

pit rem(pit it){
    debug("- %d~%d %d\n",it->L,it->R,it->T);
    pit it2 = it;
    it2++;
    sum -= (ll) (it->R-it->L+1) * (it->T);
    S.erase(it);
    return it2;
}

void add(int l,int r,int s){
    if(l > r) return;
    debug("+ %d~%d %d\n",l,r,s);
    sum += (ll) (r-l+1) * s;
    S.insert(ppi(pii(l,r),s));
}

int main() {
    int n;
    ll ans = 0;
    scanf("%d",&n);
    for(int i=1,a;i<=n;i++){
        scanf("%d",&a);
        pos[a].pb(i);
    }
    for(int i=1;i<maxn;i++){
        vector<int> v;
        for(int j=i;j<maxn;j+=i)
            for(int k=0;k<pos[j].size();k++)
                v.pb(pos[j][k]);
        sort(v.begin(),v.end());
        if(v.size() < 2) continue;
        sw[n+1].pb(pii(v[1],i));
        sw[v[v.size()-1]].pb(pii(v[0],i));
        sw[v[v.size()-2]].pb(pii(0,i));
    }
    
    add(0,n+1,0);
    for(int i=n+1;i>=2;i--){
        for(int j=0;j<sw[i].size();j++){
            int x = sw[i][j].first, y = sw[i][j].first-1, val = sw[i][j].second;
            debug("x %d val%d\n",x,val);
            pit it = S.lower_bound(ppi(pii(x+1,-1),-1));
            it--;
            while(it != S.end()){
                if(it->T >= val)
                    break;
                y = it->R;
                if(it->L < x){
                    int a = it->L, b = x-1, c = it->T;
                    it = rem(it);
                    add(a,b,c);
                }
                else
                    it = rem(it);
            }
            add(x,y,val);
        }
        while(S.size() && S.rbegin()->R >= i-1){
            if(S.rbegin()->L >= i-1)
                rem(--S.end());
            else {
                int a = S.rbegin()->L, b = i-2, c = S.rbegin()->T;
                rem(--S.end());
                add(a,b,c);
            }
        }
        ans += sum;
        debug("+ %lld\n",sum);
    }
    printf("%lld\n",ans);
}