//satyaki3794
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define MOD (1000000007LL)
#define LEFT(n) (2*(n))
#define RIGHT(n) (2*(n)+1)
 
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;
 
ll pwr(ll base, ll p, ll mod=MOD){
ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
}


ll gcd(ll a, ll b){
    if(b == 0)  return a;
    return gcd(b, a%b);
}


typedef pair<string, string> pss;
typedef pair<int, pair<string, string>> piss;
int a, b, k, f, n, cost[305];
string src[305], dest[305];
map<pss, int> totcost;



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>a>>b>>k>>f;
    for(int i=1;i<=n;i++){
    	cin>>src[i]>>dest[i];
    	if(i > 1 && dest[i-1] == src[i])	cost[i] = b;
    	else	cost[i] = a;
    	totcost[pss(min(src[i], dest[i]), max(src[i], dest[i]))] += cost[i];
    }

    vector<piss> arr;
    for(auto it : totcost)
    	arr.pb(piss(it.ss, it.ff));
    sort(arr.begin(), arr.end(), greater<piss>());

    int ans = MOD;
    n = (int)arr.size();
    for(int t=0;t<=min(n, k);t++){
    	int temp = 0;
    	for(int i=0;i<t;i++)	temp += f;
    	for(int i=t;i<n;i++)	temp += arr[i].ff;
    	ans = min(ans, temp);
    }

    cout<<ans;
    return 0;
}