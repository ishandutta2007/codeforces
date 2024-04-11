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

int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vi a(n); loop(i,0,n) cin>>a[i];
    map<int,int> last; last[0]=0;
    int maxi = -1, sum=0, ans=0;
    loop(i,0,n){
        sum+=a[i];
        if (last.find(sum)!=last.end()) chkmax(maxi, last[sum]);
        ans+=i-maxi;
        last[sum]=i+1;
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
3
1 2 -3

*/