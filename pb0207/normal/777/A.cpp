#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+1;

int main()
{
	int n,x;
	cin>>n>>x;
	int pos[3];
	n%=6;
	pos[1]=1;pos[0]=0;pos[2]=2;
	while(n)
	{
		if(n%2==0)swap(pos[1],pos[2]);
		else	swap(pos[0],pos[1]);
		n--;
	}
	for(int i=0;i<=2;++i)
	if(pos[i]==x)cout<<i;
}