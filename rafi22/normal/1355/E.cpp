#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n,a,s,m;
	cin>>n>>a>>s>>m;
	long long tab[n];
	for(int i=0;i<n;i++) cin>>tab[i];
	long long l=0,p=10e9,sr,add,sub,ans1,ans2;
	while(l<p)
	{
		sr=(l+p)/2;
		add=0,sub=0;
		for(int i=0;i<n;i++)
		{
			if(tab[i]>sr) sub+=tab[i]-sr;
			else add+=sr-tab[i];
		}
		if(m<a+s) ans1=min(add,sub)*m+(add-min(add,sub))*a+(sub-min(add,sub))*s;
		else ans1=add*a+sub*s;
		add=0,sub=0;
		for(int i=0;i<n;i++)
		{
			if(tab[i]>sr+1) sub+=tab[i]-(sr+1);
			else add+=(sr+1)-tab[i];
		}
		if(m<a+s) ans2=min(add,sub)*m+(add-min(add,sub))*a+(sub-min(add,sub))*s;
		else ans2=add*a+sub*s;
		if(ans1<=ans2) p=sr;
		else l=sr+1;
	}
    sr=l;
    add=0,sub=0;
    for(int i=0; i<n; i++)
    {
        if(tab[i]>sr)
            sub+=tab[i]-sr;
        else
            add+=sr-tab[i];
    }
    if(m<a+s)
        ans1=min(add,sub)*m+(add-min(add,sub))*a+(sub-min(add,sub))*s;
    else
        ans1=add*a+sub*s;
    cout<<ans1;
	return 0;
}