#include <bits/stdc++.h>
using namespace std;


int main() {
	int a,b,q,l,r;
	cin>>a>>b>>q;
	map <int,bool> mapa;
	vector <int> dzielniki;
	for(int i=1;i<=sqrt(a);i++)
	{
		if(a%i==0)
		{
			mapa[i]=1;
			mapa[a/i]=1;
		}
	}
	for(int i=1;i<=sqrt(b);i++)
	{
		if(b%i==0)
		{
			if(mapa[i]) dzielniki.push_back(i);
			if(mapa[b/i]) dzielniki.push_back(b/i);
		}
	}
	sort(dzielniki.begin(),dzielniki.end(),greater<int>());
	for(int i=0;i<q;i++)
	{
		cin>>l>>r;
		bool x=0;
	    for(int j=0;j<dzielniki.size();j++)
	    {
	    	if(dzielniki[j]>=l&&dzielniki[j]<=r) 
	    	{
	    		x=1;
	    		cout<<dzielniki[j]<<endl;
	    		break;
	    	}
	    }
	    if(!x) cout<<-1<<endl;
	}
	
	return 0;
}