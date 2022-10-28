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
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
 
ll pwr(ll base, ll p, ll mod=MOD){
ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
}
 
 
ll gcd(ll a, ll b){
    if(b == 0)  return a;
    return gcd(b, a%b);
}



const int N = 100002;
int n, m, arr[N], rencost[N], demcost[N];
vector<ii> storage;
vector<int> choices[N];



int main(){
 
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++){
    	scanf("%d", &arr[i]);
    	storage.pb(ii(arr[i], MOD+i));
    }
    for(int i=1;i<=m;i++){
    	scanf("%d", &rencost[i]);
    	storage.pb(ii(rencost[i], i));
    }
    for(int i=1;i<=m;i++){
    	scanf("%d", &demcost[i]);
    }

    sort(storage.begin(), storage.end(), greater<ii>());
    int idx = 0;
    for(auto it : storage){
    	if(it.ss > MOD){
    		idx = max(idx, it.ss - (int)MOD);
    	}
    	else{
    		choices[idx].pb(demcost[it.ss]);
    	}
    }

    for(int i=1;i<=n;i++)
    	sort(choices[i].begin(), choices[i].end());

    priority_queue<int> pq;
    int ans = 0;
    ll money = 0;
    for(int i=1;i<=n;i++){
    	money += arr[i];
    	for(auto it : choices[i]){
    		if(money >= it){
    			money -= it;
    			ans++;
    			pq.push(it);
    			continue;
    		}
    		if(!pq.empty() && pq.top() > it){
    			money += pq.top();
    			pq.pop();
    			money -= it;
    			pq.push(it);
    		}
    	}
    }

    printf("%d\n", ans);
    return 0;
}