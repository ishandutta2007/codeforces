#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long
#define double long double
#define pb(a) push_back(a)
#define MAX (int)(2*pow(10,5) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = pow(10,9)+7;





void deal(){
	ll m, n , k, t;
	cin>>m>>n>>k>>t;
	vector<ll> arr(m);
	fori(m){
		cin>>arr[i];
	}
	sort(arr.rbegin(), arr.rend());
	vector<vector<ll>> all(k, vector<ll>(3));
	fori(k){
		forj(3){
			cin>>all[i][j];
		}
	}
	sort(all.begin(), all.end());
	ll lo = 0 , hi = m;
	while(lo < hi){
		ll mid = (lo+hi)/2 + 1;
		// we are taking mid number of soldiers with us
		ll s = n+1;
		ll mn = -1, mx = -2;
//		cout<<"k is "<<k<<" mid is "<<mid<<" midth element is "<<arr[mid-1]<<endl;
		fori(k){
//			cout<<" all for "<<i+1<<" is "<<all[i][0]<<" "<<all[i][1]<<" "<<all[i][2]<<endl;
			if(all[i][2] > arr[mid-1]){
	//			cout<<"we took it "<<endl;
				if(all[i][0] <= mx){
					mx = max(mx, all[i][1]);			
				}
				else{
					s+=2*(mx-mn+1);
					mn = all[i][0];
					mx = all[i][1];
				}
			}
		}
	//	cout<<mn<<" "<<mx<<endl;
		s+=2*(mx-mn+1);
	//	cout<<"with "<<mid<<" soldiers it took us "<<s<<" seconds "<<endl;
		if( s<= t){
			lo = mid;
		}
		else{
			hi = mid-1;
		}
	}
	cout<<lo;
}
  
  
  
  
  
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}