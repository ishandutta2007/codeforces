#include <bits/stdc++.h>
#define maxn 200200
#define ll long long
#define pii pair<int,int>
#define pip pair<ll,pii>
#define l second.first
#define r second.second
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    deque<pip> Q;
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        Q.push_back(pip(a,pii(i,i)));
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int w,h;
        scanf("%d%d",&w,&h);
        ll ans = 0;
        while(Q.size() && Q.begin()->r < w){
            ans = max(ans,Q.begin()->first);
            Q.pop_front();
        }
        if(Q.size() && Q.begin()->l < w){
            ll t = Q.begin()->first;
            int f = Q.begin()->r;
            Q.pop_front();
            Q.push_front(pip(t,pii(w,f)));
            ans = max(ans,t);
        }
        printf("%lld\n",ans);
        Q.push_front(pip(ans+h,pii(0,w-1)));
    }
    
}