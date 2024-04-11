#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;--i)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD = 1e9+7;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vii div(n+1);
    loop(i,0,n+1) div[i] = {0,i};
    loop(i,1,n+1){
        for(int j=2*i;j<=n;j+=i){
            div[j].x = i;
        }
    }
    sort(all(div));
    loop(i,2,n+1) cout<<div[i].x<<" ";
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ f.cpp -o a & a
2


*/