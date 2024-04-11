#include <bits/stdc++.h>
using namespace std;
 #define MOD 998244353
 #define A '@'
 #define B '*'
 #define C '#'
 #define max(a,b) ((a>b)?a:b)
 #define endl "\n"
 struct frac {long x; long y;};
 
 long long pfmax[100001],p[100001];
 vector<long long > lis;
long long t,k,n,m, i,j,mid,b,c,res=0;
long long a[100001],dp[100001];
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin>>n;
   for (i=2;i<=100000;i++) 
   {
   	p[i]=1;
   }
   k=0;
   for (i=2;i<=100000;i++) 
   {
   	if (p[i]) {k++; p[i]=k; for (j=i*i;j<=100000;j+=i) p[j]=0;}
   }
   for (i=1;i<=n;i++)
   {
   	cin>>a[i];
   	lis.clear();
   	j=2;
   	while (j*j<=a[i]) {if (!(a[i]%j))
   	{
   		lis.push_back(j);
   		while (!(a[i]%j)) a[i]/=j;
   		
   	}
   		j++;
   	}
   	if (a[i]>1) lis.push_back(a[i]);
   	for (j=0;j<lis.size();j++) {if (pfmax[p[lis[j]]]>dp[i]) dp[i]=pfmax[p[lis[j]]]; }
   	dp[i]++;
   	for (j=0;j<lis.size();j++)  pfmax[p[lis[j]]]=dp[i];
   	if (res<dp[i]) res=dp[i];
   	
   }
   cout<<res;
}
/*
I don't want a lot for Christmas
There is just one thing I need
I don't care about bi D
That I toang yesterday
I just want you for my own
More than you could ever know
Make my wish come true oh
All I want for Christmas is tm
*/