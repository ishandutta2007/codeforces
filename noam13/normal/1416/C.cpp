#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e9;
 
struct SEG{
    int sz;
    vi a;
    SEG(int n){
        for(sz=1;sz<n;sz*=2);
        a.resize(2*sz);
    }
    void update(int i){
        a[i+=sz]++;
        for(i/=2; i; i/=2) a[i] = a[2*i]  +a[2*i+1];
    }
    int sum(int l, int r){
        int res = 0;
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2) res+=a[l++];
            if (r%2==0) res+=a[r--];
        }
        return res;
    }
};
int n;
int getv(vi& a){
    map<int, int> mp;
    loop(i,0,n) mp[a[i]];
    int cnt = 0;
    for(auto &x:mp) x.y = cnt++;
    SEG seg(cnt+1);
    int ans = 0;
    loop(i,0,n){
        int x = mp[a[i]];
        ans+=seg.sum(x+1, cnt);
        seg.update(x);
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    vi a(n); loop(i,0,n) cin>>a[i];
    int x = 0;
    loopr(k,0,32){
        vii top(n);
        loop(i,0,n){
            top[i] = {a[i]>>(k+1), i};
        }
        sort(all(top));
        int v1=0, v2=0, last = -1;
        vi cur;
        for(auto p:top){
            if (p.x!=last){
                int z = 0, o = 0;
                for(auto i:cur){
                    int v = a[i] & (1<<k);
                    if (v) o++, v2+=z;
                    else z++, v1+=o;
                }
                cur.clear();
            }
            cur.pb(p.y);
            last = p.x;
        }
        int z = 0, o = 0;
        for(auto i:cur){
            int v = a[i] & (1<<k);
            if (v) o++, v2+=z;
            else z++, v1+=o;
        }
        cur.clear();
        if (v1>v2) {
            x^=(1<<k);
            loop(i,0,n) a[i]^=(1<<k);
        }
    }
    cout<<getv(a)<<" "<<x<<endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
 
*/