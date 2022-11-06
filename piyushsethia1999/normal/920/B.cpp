#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int 
#define pb push_back

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,t,l[1000],r[1000];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>l[i]>>r[i];
		}
		int pos=0;
		int time=1;
		while(pos<n){
			if(time>=l[pos]&&time<=r[pos]){
				cout<<time<<" ";
				time++;
				pos++;
			}
			else if(time<l[pos]){
				time=l[pos];
			}
			else if(time>r[pos]){
				cout<<"0 ";
				pos++;
			}
		}
		cout<<"\n";
	}
}