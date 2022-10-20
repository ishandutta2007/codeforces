#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[1001000], c[1001000];
ll b[1001000], b2[1001000];

ll get_rand(){
    ll ret = 0;
    for (int i=0;i<60;i++) if (rand()&1) ret |= (1LL<<i);
    return ret;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%d", a+i);
    int ans = 0;
    for (int z=22;z>=0;z--){
        //printf("%d: ", z);
        //for (int i=0;i<=n;i++) printf("%lld ", b[i]);
        //printf("\n");
        vector<pair<pair<ll, ll>, int>> v;
        c[0] = 0;
        v.emplace_back(make_pair(b[0], b2[0]), 0);
        for (int i=1;i<=n;i++){
            v.emplace_back(make_pair(b[i], b2[i]), i);
            c[i] = c[i-1];
            if (!(a[i]&(1<<z))) c[i]++;
        }
        sort(v.begin(), v.end());
        //printf("YES\n");
        int r = 0;
        for (int i=0;i<=n;i=r){
            while(r<=n && v[i].first==v[r].first) r++;
            int pt = i+1;
            //if (z==2) printf("%d %d\n", i, r);
            for (int j=i;j<r;j++){
                if (pt<=j) pt = j+1;
                while(pt<r && c[v[j].second]==c[v[pt].second] && (a[v[j].second+1]&(1<<z)) && (a[v[pt].second]&(1<<z))){
                    ans = max(ans, v[pt].second-v[j].second);
                    //printf("%d: %d %d\n", z, v[pt].second, v[j].second);
                    pt++;
                }
            }
        }

        ll tmp = get_rand(), tmp2 = 0, tmp3 = get_rand();
        for (int i=1;i<=n;i++){
            if (!(a[i]&(1<<z))) tmp2 ^= 1;
            b[i] ^= tmp*tmp2;
            b2[i] ^= tmp3*tmp2;
        }
    }
    printf("%d\n", ans);
    return 0;
}