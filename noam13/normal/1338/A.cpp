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
const int INF = 1e18, MOD = 1e9+7;
int n;
vi a;
bool can(int k){
	int maxi = -INF;
	loop(i,0,n){
		int dif = maxi-a[i];
		if (dif>=(int(1)<<(k))) return 0;
		chkmax(maxi, a[i]);
	}
	return 1;
}
int solve(){
    cin>>n;
    a = vi(n);
    loop(i,0,n) cin>>a[i];
    int l=0,r=60,mid,ans=-1;
    while(l<r){
    	mid = (l+r)/2;
    	if (can(mid)) r=mid, ans=mid;
    	else l = mid + 1;
    }
    cout<<ans<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a


*/