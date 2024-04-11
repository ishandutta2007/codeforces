#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define ll long long 
#define MAX (int)(pow(10,7) + 10)
#define maxbit 27
#define pb(a) push_back(a)
// #define cout out
// #define cin in
ll inf = pow(10,18);
ll modulo = pow(10,9) + 7;
double eps = 1e-6;
ifstream in;
ofstream out;

int dp[MAX];

ll add(ll cur, ll s1, ll s2 ){
	ll bd1 = s1-cur;
	ll bd2 = s2-cur;
	--bd1;
//	cout<<"bd1 bd2 for"<<cur<<" is "<<bd1<<" "<<bd2<<endl;
	bd2 = min(bd2, cur-1);
	bd1 = min(bd1, cur-1);
	ll s =0 ;
	if(bd2>=0){
		s += dp[bd2];
	}
	if(bd1>=0){
		s-=dp[bd1];
	}
	return s;
}

void deal(){
	ll n ;
	cin>>n;
	vector<ll> arr(n);
	fori(n){
		cin>>arr[i];
	}
	ll tot = 0;
	for(ll j =0; j<maxbit; j++){
		ll cur = 0;
		// up to and including jth bit, try to figure out number of combinations where jth bit is on
//		cout<<"we at "<<j<<"th bit"<<endl;
		fori(n){
			ll ed = arr[i];
			ed &= (  (1<<(j+1)) -1);
//			cout<<arr[i]<<" turned into "<<ed<<endl;
			dp[ed]++;
			// turn off all the bits bigger than jth bit
		}
		for(ll i =1; i<MAX; i++){
			dp[i]+=dp[i-1];
		}
		
		ll s1 = (1<<j);
		ll s2 = ((1<<(j+1)) - 1);
		ll s3 = (1<<j) + (1<<(j+1));
		ll s4 = ((1<<(j+2))-1);
		
		
		ll loop = min(MAX, (1<<(j+1)));
		for(ll i = 1; i<loop; i++){
			ll now = (dp[i]-dp[i-1]);
			cur+=now*add(i, s1,s2);
			cur+=now*add(i, s3,s4);
			if((i+i)&(1<<j)){
				cur+=now*(now-1)/2;
			}
		}
		
		fori(MAX){
			dp[i] = 0;
		}
//		cout<<"for "<<j<<"th bit we got "<<cur<<endl;
		if(cur&1){
			tot^=(1<<j);
		}
	}
	cout<<tot<<endl;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}



/* 
6 8 
1 2
2 3
3 4
4 1
2 5
3 5
1 6
4 6
*/