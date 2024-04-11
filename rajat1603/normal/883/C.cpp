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



 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll f, T, t0;
    cin>>f>>T>>t0;

    ll a1, t1, p1;
    cin>>a1>>t1>>p1;

    ll a2, t2, p2;
    cin>>a2>>t2>>p2;

    if(t1 > t2){
    	swap(a1, a2);
    	swap(t1, t2);
    	swap(p1, p2);
    }

    if(t0*f <= T){
    	//no special plan needed
    	cout<<"0";
    	return 0;
    }

    ll ans = (ll)1e18;
    ll z = (f+a1-1)/a1;

    for(ll i=0;i<=z;i++){

    	//i is number of times I use plan-1

   		ll cost = p1*i;
    	if(a1*i >= f){
    		//all data downloaded
    		if(f*t1 > T)	continue;
    		ans = min(ans, cost);
    		continue;
    	}

    	if(i*a1*t1 >= T){
    		//no time left but more data needs to be downloaded
    		continue;
    	}

    	ll rem_time = T - t1*i*a1, rem_data = f-a1*i;
    	if(log2(rem_data) + log2(t0) > log2(1e15))	continue;
    	ll normally_taken_time = rem_data*t0;
    	if(normally_taken_time <= rem_time){
    		//after using plan-1 for i times, I can download remaining data using regular package
    		ans = min(ans, cost);
    		continue;    		
    	}

    	//I definitely have to use plan-2 too

    	ll extra = normally_taken_time - rem_time;

    	ll diff = t0 - t2;

    	//every byte converted from regular to plan-2 reduces total time by diff
    	//if t2 >= t0, no point in using plan-2

    	if(diff <= 0)	continue;


    	ll n = (extra + (diff-1)) / diff;
    	if(n > rem_data)	continue;
    	//n is min number of bytes I need to use plan-2 on

    	ll needed = (n+a2-1)/a2;

    	cost += needed*p2;
    	ans = min(ans, cost);
    }


    if(ans >= (ll)1e16)	ans = -1;
    cout<<ans;
    return 0;
}