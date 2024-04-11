#include<bits/stdc++.h>
#define pi 3.14159265
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
ll n,a[100100],sum1[100100],sum2[100100];
multiset<ll>s1,s2;
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	cin>>n;
	forr(i,1,n)
	{
	    cin>>a[i];
	    sum1[i]=a[i]+sum1[i-1];
	 
	}
	if(n==1||sum1[n]%2==1)
	{
	    cout<<"NO";
	    return 0;
	}
	forr(i,0,n)
	{
	   auto it1=lower_bound(sum1+i+1,sum1+n+1,sum1[n]/2+a[i]);
	   if(*it1==sum1[n]/2+a[i])
	    {
	       cout<<"YES";
	        return 0;
	    }
	}
	reverse(a+1,a+1+n);
	forr(i,1,n)
	    sum2[i]=a[i]+sum2[i-1];
	 
	forr(i,0,n)
	{
	    auto it1=lower_bound(sum2+i+1,sum2+n+1,sum2[n]/2+a[i]);
	    if(*it1==sum2[n]/2+a[i])
	    {
	        cout<<"YES";
	        return 0;
	    }
	}
	 cout<<"NO";
	return 0;
}