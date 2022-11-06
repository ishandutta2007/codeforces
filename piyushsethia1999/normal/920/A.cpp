#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int 
#define pb push_back

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k,A[200];
	int t,a,b,max,i;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		cin>>A[0];
		max=A[0];
		for(i=1;i<k;i++)
		{
			cin>>A[i];
			if(max<((A[i]-A[i-1])/2+1))
				max=(A[i]-A[i-1])/2+1;
		}
		if((n-A[i-1]+1)>max){
			max=n-A[i-1]+1;

		}
		cout<<max<<"\n";
	}
}