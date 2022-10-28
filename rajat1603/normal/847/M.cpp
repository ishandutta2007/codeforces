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


int arr[1002];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    bool AP = true;
    for(int i=1;i<=n;i++){
    	cin>>arr[i];
    	if(i == 1)	continue;
    	int d = arr[2]-arr[1];
    	if(arr[i] != arr[1] + (i-1)*d)	AP = false;
    }

    if(AP)	cout<<arr[n] + arr[2]-arr[1];
    else	cout<<arr[n];
    return 0;
}