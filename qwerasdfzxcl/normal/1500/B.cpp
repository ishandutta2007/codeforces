#include <bits/stdc++.h>
#define int long long
using namespace std;

int pos[1001000], b[500500], n, m, k, L, G, inv, x, y;
vector<int> ang;

int calc(int p, int q){
    if ((q-p+L)%G) return -1;
    int d = ((q-p+L)/G)%y;
    d = (d*inv)%y;
    return n*d+p;
}

signed main(){
    scanf("%lld %lld %lld", &n, &m, &k);
    k--;
    L = n*m/(__gcd(n, m)), G=__gcd(n, m);
    x = n/G, y = m / G;
    for (int i=0;i<y;i++) if ((x*i)%y==1){
        inv = i; break;
    }
    fill(pos, pos+1001000, -1);
    for (int i=0;i<n;i++){
        int tmp;
        scanf("%lld", &tmp);
        pos[tmp]=i;
    }
    for (int i=0;i<m;i++){
        scanf("%lld", b+i);
        if (pos[b[i]]==-1) continue;
        int tmp = calc(pos[b[i]], i);
        if (tmp!=-1) ang.push_back(tmp);
    }
    sort(ang.begin(), ang.end());
    //for (int x:ang) printf("%lld ", x);
    //printf("\n");
    int ans = k/(L-(int)ang.size())*L;
    //printf("%lld %lld\n", ans, L);
    k %= (L-(int)ang.size());
    int cur = k, idx;
    idx = upper_bound(ang.begin(), ang.end(), k)-ang.begin();
    while(cur-idx<k){
        cur++;
        if (idx<(int)ang.size() && ang[idx]==cur){
            idx++;
        }
    }
    ans += cur;
    printf("%lld\n", ans+1);
    return 0;
}