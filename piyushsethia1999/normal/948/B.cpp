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
bool isNotPrime[1000001]={false};
std::vector<int> v;
void SieveofErastothenes(int n){
	int t=sqrt(n);
	for(int i=2;i<=t;i++)
	{
		if(!isNotPrime[i]){
			v.pb(i);
			for(int j=i*i;j<=n;j+=i)
			{
				isNotPrime[j]=true;
			}
		}
	}
}
int findLargestPrimeFactor(int n){
	std::vector<int>::iterator it;
	int q;
	while(isNotPrime[n]){
		q=sqrt(n);
		for(it = v.begin(); (*it)<=q;it++){
			if(!(n%(*it))){
				n/=(*it);
				break;
			}
		}
	}
	return n;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	SieveofErastothenes(1000000);
	int x2;
	cin>>x2;
	int p=findLargestPrimeFactor(x2);
	int w=x2-p;
	int min=1000000;
	for (int i = x2; i > w; --i)
	{
		p=findLargestPrimeFactor(i);
		if(p!=i){
			if(min>(i-p+1))
				if((i-p+1)>=3)
					min=(i-p+1);
		}
	}
	cout<<min;
}