#include <bits/stdc++.h>
#define INF 1000010
#define N 105
using namespace std;
int main(){
	int n,i,a[N],ans=0;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n-1;i++)
	{
		if(a[i]+a[i+1]==5)
			ans=INF;
		else
			ans+=(a[i]+a[i+1]);
		if(a[i]==1&&a[i+1]==2&&a[i-1]==3&&i)
			ans--;
	}
	if(ans>=INF)
		cout<<"Infinite"<<endl;
	else
		cout<<"Finite"<<endl<<ans<<endl;
	return 0;
}