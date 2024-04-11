#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> prime;
vector<ll> ex;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--){
        ll p, q;
        scanf("%lld %lld", &p, &q);
        if (p%q!=0) printf("%lld\n", p);
        else{
            bool test=0;
            for (ll i=2;i<100000;i++){
                if (!test && q%i==0) test=1;
                if (q%i==0) {
                    prime.push_back(i);
                    ex.push_back(0);
                }
                while (q%i==0){
                    q/=i;
                    ex[ex.size()-1] += 1;
                }
                if (q==1) break;
            }
            if (!test) {
                prime.push_back(q);
                ex.push_back(1);
            }
            ll ans=-1000000000000000;
            for (int i=0;i<prime.size();i++){
                //printf("%lld %lld\n", prime[i], ex[i]);
                ll tmp=p;
                while (tmp%prime[i]==0) tmp/=prime[i];
                for (ll j=0;j<ex[i]-1;j++){
                    tmp *= prime[i];
                }
                ans=max(ans, tmp);
            }
            printf("%lld\n", ans);
        }
        prime.clear();
        ex.clear();
    }
    return 0;
}