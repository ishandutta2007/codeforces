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
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18;

void solve(){
    int n,k; cin>>n>>k;
    const int sz=100;
    vb used(sz,0);
    bool pos=true;
    loop(i,0,n) {
        int a; cin>>a;
        for(int cnt=0;a!=0 && cnt<sz;cnt++, a=a/k){
            if (a%k==0) continue;
            if (a%k==1 && !used[cnt]) used[cnt]=1;
            else pos=false;
        }
    }
    cout<<(pos?"YES":"NO")<<endl;
}
int32_t main(){
    //ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
5
4 100
0 0 0 0
1 2
1
3 4
1 4 1
3 2
0 1 3
3 9
0 59049 810

*/