#include <bits/stdc++.h>
using namespace std;
int main(){
	int t1,t2,a,b,i,ans=0;
	cin>>t1>>t2>>a>>b;
	if(a<=b&&a*8<t2-t1)
	{
		cout<<-1<<endl;
		return 0;
	}
	while(t1<t2)
	{
		t1+=a*8;
		if(t1>=t2)
		{
			break;
		}
		ans++;
		t1-=b*12;
		t1+=a*4;
		if(t1>=t2)
		{
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}