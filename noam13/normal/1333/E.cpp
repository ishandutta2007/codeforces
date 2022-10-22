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
const int INF = 1e18, MAXN = 3e3+2, MAXK = 3e6+2;


int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    int sol[3][3] = { {8,6,5},
                    {7,3,9},
                    {4,2,1}};
    if (n<3) return cout<<-1<<endl,0;
    vvi ans(n, vi(n));
    int cnt = 0;
    loop(k,0,n-3){
        loop(i,0,n-k) ans[n-k-1][i]=cnt++;
        loop(i,0,n-k-1) ans[i][n-k-1]=cnt++;
    }
    loop(i,0,3) loop(j,0,3) ans[i][j] = sol[i][j]+cnt-1;
    loop(i,0,n) {loop(j,0,n) cout<<ans[i][j]+1<<" "; cout<<endl;}
    return 0;
}
/*
color a
cls
g++ e.cpp -o c & c
5





*/