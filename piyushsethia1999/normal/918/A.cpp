#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int 
#define pb push_back

using namespace std;

int F[20];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	F[0]=1;
	F[1]=2;
	for(int i=2;i<20;i++)
	{
		F[i]=F[i-1]+F[i-2];
	}
	int j=0;
	for(int i=1;i<=n;i++)
	{
		if(i==F[j]){
			cout<<"O";
			j++;
		}
		else
		{
			cout<<"o";
		}
	}
}