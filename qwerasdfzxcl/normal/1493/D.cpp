#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
unordered_map<int, int> tree[800800];
vector<int> prime;
bool pchk[200200];
int n, a[200200];
ll MOD=1e9+7;
vector<pair<int, int>> tmp;

int pw(int a, int e){
    if (!e) return 1;
    int tmp2=pw(a, e/2);
    int ret=tmp2*tmp2;
    if (e&1) ret *= a;
    return ret;
}

vector<pair<int, int>> pd(int x){
    vector<pair<int, int>> factor;
    for (int p:prime){
        if (x==1) break;
        if (pchk[x]){
            factor.push_back(make_pair(x, 1));
            return factor;
        }
        if (x%p) continue;
        factor.push_back(make_pair(p, 0));
        while(!(x%p)){
            x /= p; factor.back().second++;
        }
    }
    assert(x==1);
    return factor;
}

void build(int i, int l, int r){
    if (l==r){
        tmp=pd(a[l]);
        for (auto &p:tmp){
            tree[i][p.first] = p.second;
        }
        return;
    }
    int m=(l+r)>>1;
    build(i*2, l, m); build(i*2+1, m+1, r);
    if (tree[i*2].size()<tree[i*2+1].size()){
        //printf("YES\n");
        auto iter=tree[i*2].begin();
        while(iter!=tree[i*2].end()){
            if (tree[i*2+1].find(iter->first)==tree[i*2+1].end()){
                ++iter; continue;
            }
            tree[i][iter->first]=min(iter->second, tree[i*2+1][iter->first]);
            ++iter;
        }
    }
    else{
        //printf("YES2\n");
        auto iter=tree[i*2+1].begin();
        while(iter!=tree[i*2+1].end()){
            if (tree[i*2].find(iter->first)==tree[i*2].end()){
                ++iter; continue;
            }
            tree[i][iter->first]=min(iter->second, tree[i*2][iter->first]);
            ++iter;
        }
    }
    //printf("%d %d %d\n", i, l, r);
}

int update(int i, int l, int r, int idx, int val){
    if (idx<l || idx>r) return 1;
    if (idx==l && idx==r){
        tmp=pd(val);
        for (auto &p:tmp){
            if (tree[i].find(p.first)==tree[i].end()) tree[i][p.first]=p.second;
            else tree[i][p.first] += p.second;
        }
        return val;
    }
    int m=(l+r)>>1;
    int t1=update(i*2, l, m, idx, val), t2=update(i*2+1, m+1, r, idx, val);
    if (t1==1 && t2==1) return 1;
    tmp=pd(max(t1, t2));
    int ret=1;
    for (auto &pp:tmp){
        int p=pp.first;
        if (tree[i*2].find(p)==tree[i*2].end() || tree[i*2+1].find(p)==tree[i*2+1].end()) continue;
        if (tree[i].find(p)==tree[i].end()){
            ret *= pw(p, min(tree[i*2][p], tree[i*2+1][p]));
            tree[i][p]=min(tree[i*2][p], tree[i*2+1][p]);
        }
        else{
            ret *= pw(p, min(tree[i*2][p], tree[i*2+1][p])-tree[i][p]);
            tree[i][p]= min(tree[i*2][p], tree[i*2+1][p]);
        }
    }
    return ret;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    fill(pchk, pchk+200200, 1);
    pchk[0]=0, pchk[1]=0;
    for (int i=2;i<200200;i++){
        if (!pchk[i]) continue;
        prime.push_back(i);
        for (int j=2;i*j<200200;j++) pchk[i*j]=0;
    }
    int q;
    cin >> n >> q;
    for (int i=1;i<=n;i++) cin >> a[i];
    build(1, 1, n);
    ll ans=a[1];
    for (int i=2;i<=n;i++) ans=__gcd(ans, (ll)a[i]);
    while(q--){
        int a, b;
        cin >> a >> b;
        int val=update(1, 1, n, a, b);
        ans = (ans*val)%MOD;
        cout << ans << '\n';
    }
    return 0;
}