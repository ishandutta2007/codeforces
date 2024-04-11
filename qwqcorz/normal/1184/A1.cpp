#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll r;

int main()
{
	cin>>r;
	if ((r&1)&&r>3) printf("1 %lld\n",(r-3)/2);
			   else printf("NO\n");

	return 0;
}