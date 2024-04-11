#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> v(100002);
vector<ll> sum(100002);
map<ll, bool> poss;
int n, q;

void solve(int l, int r)
{
    if(l > r) return;
    if(l == r) { poss[v[r]] = true; return; }
    poss[sum[r+1] - sum[l]] = true;
    if(v[l] == v[r]) return;
    int m = upper_bound(v.begin()+l-1, v.begin()+r, (v[r] + v[l])/2) - v.begin();
    solve(l, m-1); solve(m, r);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        poss.clear();
        scanf("%d %d", &n, &q);
        for(int i=0;i<n;i++){
            scanf("%lld", &v[i]);
        }
        sort(v.begin(), v.begin()+n);
        sum[0] = 0;
        for(int i=1;i<=n;i++){
            sum[i] = sum[i-1] + v[i-1];
        }
        solve(0, n-1);
        for(int i=1;i<=q;i++){
            ll s;
            scanf("%lld", &s);
            if(poss[s]) printf("Yes\n");
            else printf("No\n");
        }
    }
}