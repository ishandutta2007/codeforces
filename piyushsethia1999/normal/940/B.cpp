#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int
#define pb push_back
#define mp make_pair
#define ii pair<int,int>
#define vi vector<int>
#define iii pair<int,pair<int,int>>
#define INF (1<<30)

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k,A,B;
	cin>>n>>k>>A>>B;
	ll sum=0;
	while(n>1){
		sum+=((n%k)*A);
		n=n-n%k;
		if((n-(n/k))*A>(B)&&k<=n){
			sum+=B;
			n/=k;
		}
		else{
			sum+=((n-1)*A);
			break;
		}
	}
	cout<<sum;

}