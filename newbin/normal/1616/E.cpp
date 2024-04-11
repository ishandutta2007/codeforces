#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
#define lowbit(x) (x&(-x))
using namespace std;
const int maxn = 1e5+5;
int q, n;
char s[maxn];
char t[maxn];
int a[maxn];
void add(int i, int x){
    while(i <= n) a[i] += x, i += lowbit(i);
}
int qry(int i){
    int res = 0;
    while(i) res += a[i], i -= lowbit(i); return res;
}
void init(){
    scanf("%d", &n);
    scanf("%s", s+1);
    scanf("%s", t+1);
}
const ll inf = 0x3f3f3f3f3f3f3f3f;
void sol(){
    ll ans = inf;
    vector<int> p[26];
    for(int i = n; i > 0; --i){
        int x = s[i]-'a';
        p[x].pb(i);
        add(i, 1);
    }
    ll cur = 0;
    for(int i = 1; i <= n; ++i){
        int x = t[i]-'a';
        for(int j = 0; j < x; ++j){
            if(p[j].size()){
                int pos = p[j].back();
                int ex = qry(pos)-1;
                ans = min(ans, cur+ex);
            }
        }
        if(p[x].size()){
            int pos = p[x].back(); p[x].pop_back();
            int ex = qry(pos)-1;
            cur += ex;
            add(pos, -1);
        }else break;
    }
    fors(i,0,26){
        while(p[i].size()) add(p[i].back(), -1), p[i].pop_back();
    }
    if(ans == inf) ans = -1;
    printf("%lld\n", ans);
}
int main(){
    cin>>q;
    while(q--){
        init();sol();
    }
    return 0;
}