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
const int INF = 4e18;


vvi qur;
void flip(vi& a, const vi& v){
    if (v.size()<=1) return ;
    //cout<<"QUR: ";for(auto x:v) cout<<x<<" "; cout<<endl;
    qur.pb(v);
    vvi aa(v.size());
    int i = 0;
    loop(j,0,v.size()) loop(k,0,v[j]) aa[j].pb(a[i++]);
    reverse(all(aa));
    i = 0;
    for(vi& vv:aa) for(int x:vv) a[i++] = x;
}
int n;
int find(vi& a, int v){
    loop(i,0,n) if(a[i]==v) return i;
    return -1;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    int l = n/2 + 1, r = l;
    vi a(n); loop(i,0,n) cin>>a[i];
    int pos = find(a, l);
    if (pos) flip(a, vi({pos, n-pos})); 
    l--, r++;
    bool turn = 0;
    int sz = 1;
    while(l>0 || r<=n){
        if (turn){
            pos = find(a, r++);
            int bb = n - sz;
            if (pos) flip(a, vi({pos, bb-pos, sz}));
            else flip(a, vi({bb, sz}));
        }
        else{
            pos = find(a, l--);
            if (pos==n-1) flip(a, vi({sz, n-sz}));
            else flip(a, vi({sz, pos+1-sz, n-pos-1}));
        }
        turn = !turn;
        sz++;
    }
    //cout<<"A: "; loop(i,0,n) cout<<a[i]<<" "; cout<<endl;
    cout<<qur.size()<<endl;
    for(auto q:qur) {
        cout<<q.size()<<" ";
        for(auto x:q) cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
4
3 1 2 4


*/