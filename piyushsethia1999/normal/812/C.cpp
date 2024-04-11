#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int 
#define pb push_back

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,d;
	std::vector<ll> v;
	ll A[100000];
	cin>>n>>d;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	ll start=0;
	ll end=n;
	ll mid,sum=0;
	while(start<=end){
		mid=(start+end)/2;
		for(ll i=0;i<n;i++)
			v.pb(A[i]+(i+1)*mid);
		sort(v.begin(),v.end());
		for(ll i=0;i<mid;i++)
		{
			sum+=v[i];
		}
		if(d>=sum){
			start=mid+1;
		}
		else{
			end=mid-1;
		}
		v.clear();
		sum=0;
	}
	cout<<end;
	mid=end;
		for(ll i=0;i<n;i++)
			v.pb(A[i]+(i+1)*mid);
		sort(v.begin(),v.end());
		for(ll i=0;i<mid;i++)
		{
			sum+=v[i];
		}
		cout<<" "<<sum;
}