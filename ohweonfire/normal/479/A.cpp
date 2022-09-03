#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(b==1)
		cout<<max(max(a+b+c,a*b*c),max(a*(b+c),(a+b)*c));
	else if(a==1)
		cout<<max((a+b)*c,a+b+c);
	else if(c==1)
		cout<<max(a+b+c,a*(b+c));
	else cout<<a*b*c;
	return 0;
}