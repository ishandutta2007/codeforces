#include <bits/stdc++.h>
using namespace std;
bitset<501> t,r;
long long n,k,s,a,b,c,d,i,l,j;
main()
{
	cin>>n>>k;
	t[0]=1;
	for(i=0;i<n;i++){
		cin>>a>>b;
		s+=(c+a)/k+(d+b)/k;
		c=(c+a)%k;
		d=(d+b)%k;
		r=0;
		for(j=0;j<k;j++)
			if(t[j])
				for(l=1;l<min(b+1,k);l++)
					if(k-l<=a)
						r[(j+l)%k]=1;
		t|=r;
	}
	for(i=0;i<=c+d-k;i++)
		if(t[(i-c+k)%k])
			s++,i=k;
	cout<<s;
}