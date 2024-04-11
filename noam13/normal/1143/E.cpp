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
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18;

const int LOG = 20;
int32_t main(){
    int n,m,q; cin>>n>>m>>q;
    vi p(n), pos(n); loop(i,0,n) cin>>p[i],p[i]--,pos[p[i]]=i;
    vi last(n,0);
    vi a(m+1);
    vvi jump(m+1, vi(LOG,0));
    loop(i,1,m+1){
        cin>>a[i], a[i]--;
        int pp = (pos[a[i]] + n - 1) % n;
        //cout<<"PP: "<<pp<<endl;
        jump[i][0] = last[pp];
        last[pos[a[i]]]=i;
    }
    loop(j,1,LOG) loop(i,1,m+1) jump[i][j] = jump[jump[i][j-1]][j-1];
    vi left(m+1,0);
    loop(i,1,m+1){
        int cur = i;
        loop(j,0,LOG) if((n-1) & (int(1)<<j)) cur = jump[cur][j];
        left[i] = cur;
        //cout<<cur<<" ";
    }
    loop(i,1,m+1) chkmax(left[i], left[i-1]);
    loop(i,0,q){
        int l,r; cin>>l>>r;
        cout<<(left[r]>=l?1:0);
    }
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
3 6 3
2 1 3
1 2 3 1 2 3
1 5
2 6
3 5



. . . . . . . . . . . . . . 

*/