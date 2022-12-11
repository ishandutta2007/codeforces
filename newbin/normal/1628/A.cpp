#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
int main(){
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<int> a(n);
        vector<int> cnt(n+1, 0);
        fors(i,0,n) scanf("%d", &a[i]), cnt[a[i]]++;
        int cur = 0;
        while(cnt[cur]) cur++;
        vector<int> b;
        int p = -1;
        while(p+1 < n){
            if(cur == 0){
                b.pb(0); p++; continue;
            }
            set<int> s;
            int t = p;
            while(s.size() < cur){
                if(a[t+1] < cur) s.insert(a[t+1]);
                t++;
            }
            b.pb(cur);
            for(int i = p+1; i <= t; ++i){
                cnt[a[i]]--; if(cnt[a[i]] == 0) cur = min(cur, a[i]);
            }
            p = t;
        }
        cout<<b.size()<<endl;
        for(int x:b) printf("%d ", x); printf("\n");
    }
    return 0;
}