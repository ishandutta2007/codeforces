#include <bits/stdc++.h>
using namespace std;
main()
{
	long long t,m,n,a,i,j,c;
	cin>>t;
	while(t--){
		cin>>n>>m;
		multiset<long long> p;
		while(m--)
			cin>>a,p.insert(a);
		c=0;
		for(i=1;i<=n;i*=2){
			if(n&i){
				auto it=p.lower_bound(i);
				if(it==p.end()){
					c=-1;
					break;
				}
				for(;*it!=i;it=p.lower_bound(i))
					p.insert(*it/2),p.insert(*it/2),p.erase(it),c++;
				p.erase(p.find(i));
			}
			for(j=0,m=p.count(i);j<m/2;j++)
				p.insert(2*i);
		}
		cout<<c<<endl;
	}
}