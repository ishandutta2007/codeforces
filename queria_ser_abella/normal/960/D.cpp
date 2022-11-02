#include <bits/stdc++.h>
using namespace std;
#define sq(x) ((x)*(x))
#define double long double
#define eps 1e-3
#define maxn 400400
#define pii pair<int,int> 
#define debug 
#define ll long long
#define pb push_back

ll imp[80];
ll l[80];

void mod(ll &a,ll md){
    a %= md;
    a += md;
    a %= md;
}

main(){
        
    for(int i=0;i<62;i++)
        l[i] = 1ll << (i+1);
        
    int q;
    scanf("%d",&q);
    while(q--){
        int t;
        scanf("%d",&t);
        if(t == 1){
            ll x,k;
            scanf("%I64d%I64d",&x,&k);
            int lvl = -1;
            ll aux = x;
            while(aux){
                lvl++;
                aux /= 2;
            }
            imp[lvl] -= k;
            mod(imp[lvl],1ll<<lvl);
        }
        if(t == 2){
            ll x,k;
            scanf("%I64d%I64d",&x,&k);
            int lvl = -1;
            ll aux = x;
            while(aux){
                lvl++;
                aux /= 2;
            }
            if(lvl == 0) continue;
            debug("era %I64d\n",l[lvl-1]);
            l[lvl-1] -= (1ll<<lvl);
            l[lvl-1] -= k;
            mod(l[lvl-1],1ll<<lvl);
            l[lvl-1] += (1ll<<lvl);
            debug("fica %I64d\n",l[lvl-1]);
        }
        if(t == 3){
            ll x;
            scanf("%I64d",&x);
            int lvl = -1;
            ll aux = x;
            while(aux){
                lvl++;
                aux /= 2;
            }
            x -= 1ll << lvl;
            x -= imp[lvl];
            mod(x,1ll<<lvl);
            x += 1ll << lvl;
            debug("x %I64d lvl %d l1 %lld\n",x,lvl,l[1]);
            while(lvl >= 0){
                ll y = x - (1ll << lvl);
                y += imp[lvl];
                mod(y,1ll<<lvl);
                y += 1ll << lvl;
                printf("%I64d ",y);
                ll p = 1ll << (lvl-1);
                ll walk = x-l[lvl-1];
                mod(walk,1ll<<lvl);
                debug("walk %I64d (%I64d-%I64d)\n",walk,x,l[lvl-1]);
                walk /= 2;
                x = p + walk;
                debug("x -> %I64d\n",x);
                lvl--;
            }
            printf("\n");
        }
        
    }
}