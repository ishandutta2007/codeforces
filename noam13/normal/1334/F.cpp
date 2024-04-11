#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD = 1e9+7;

struct SEG{
    int sz,h;
    vi a;
    SEG(int n){
        for(sz=1,h=0;sz<n;sz<<=1,h++);
        a.resize(2*sz,0);
    }
    void push(int p) {
        for (int s = h; s > 0; --s) {
            int i = p >> s;
            a[2*i]+=a[i]; 
            a[2*i+1]+=a[i];
            a[i] = 0;
        }
    }
    void upd(int l, int r, int x){
        for(l+=sz,r+=sz;l<=r;l>>=1,r>>=1){
            if (l%2) a[l++]+=x;
            if (r%2==0) a[r--]+=x;
            if (l>r) break;
        }
    }
    void set(int i, int x){
        i+=sz;
        push(i);
        a[i]=x;
    }
    int get(int i){
        int ans = 0;
        for(i+=sz;i;i>>=1) ans+=a[i];
        return ans;
    }
};
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n;
    vi a(n),p(n); 
    loop(i,0,n) cin>>a[i];
    loop(i,0,n) cin>>p[i];
    cin>>m; m++;
    vi b(m); b[0]=0;
    loop(i,1,m) cin>>b[i];
    map<int,int> mp;
    loop(i,0,m) mp[b[i]]=i;
    mp[INF]=-1;
    SEG seg(m);
    loop(i,1,m) seg.set(i,INF);
    seg.set(0,0);
    loop(i,0,n){
        int l=0,r=m, mid,j=-1;
        while(l<r){
            mid = (l+r)/2;
            if (b[mid]<=a[i]) l = mid + 1, j = mid;
            else r = mid;
        }
        //cout<<"CUR: "; loop(i,0,m) cout<<seg.get(i)<<" "; cout<<endl;
        /*auto it = mp.upper_bound(a[i]);
        it--;
        int j = it->y;*/
        //cout<<"IJ: "<<i<<", "<<j<<endl;
        int val = INF;
        if (j&& a[i]==b[j]){
            val = seg.get(j-1);
        }
        if (p[i]>0) seg.upd(0,j - (j&& a[i]==b[j]), p[i]);
        else seg.upd(0,m-1,p[i]);
        if (j&& a[i]==b[j]){
            int cur = seg.get(j);
            if (cur>val) seg.set(j,val);
        }
    }
    int ans = seg.get(m-1);
    if (ans>=INF/2) return cout<<"NO"<<endl,0;
    cout<<"YES"<<endl;
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ f2.cpp -o a & a
6
2 1 5 3 6 5
3 -9 0 16 22 -14
4
2 3 5 6


*/