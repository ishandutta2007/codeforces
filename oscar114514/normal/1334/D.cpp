#include<bits/stdc++.h>
using namespace std;
int n,T;
long long l,r;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>l>>r;
		if(l>1ll*n*(n-1))
		{
			cout<<1<<endl;
			continue;
		}
		long long cur=0,add=n-1;
		while(cur+add*2<l)cur+=add*2,add--;
//		cerr<<"p1 "<<cur<<endl;
		int p=n-add,q=p+1;
		while(cur+2<l)cur+=2,q++;
		if(q>n)p++,q=p+1;
//		cerr<<"p2 "<<cur<<' '<<p<<' '<<q<<endl;
		if(l%2==0)cout<<q<<' ',l++,q++,cur+=2;
		if(q>n)p++,q=p+1;
		while(cur+2<=r)
		{
			cout<<p<<' '<<q<<' ';
			cur+=2;
			q++;
			if(q>n)p++,q=p+1;
		}
		if(r>1ll*n*(n-1))
		{
			cout<<1<<endl;
			continue;
		}
		if(r%2==1)cout<<p;
		cout<<endl;
	}
	return 0;
}