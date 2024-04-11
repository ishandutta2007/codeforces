#include <bits/stdc++.h>
#define MAXN 100007
using namespace std;
int x[MAXN],y[MAXN],z[MAXN];
bool mtc[MAXN];
bool cmpx(int a, int b) {return x[a]<x[b];}
bool cmpy(int a, int b) {return y[a]<y[b];}
bool cmpz(int a, int b) {return z[a]<z[b];}
vector<int> sp,rv,pr;
int main()
{
	int n;
	cin>>n;
	fill(mtc,mtc+MAXN,false);
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i]>>z[i];
	for(int i=1;i<=n;i++) sp.push_back(i);
	sort(sp.begin(),sp.end(),cmpx);
	int t=0;
	while(t<n)
	{
		rv.clear(); rv.push_back(sp[t++]);
		while(t<n && x[sp[t]]==x[sp[t-1]]) rv.push_back(sp[t++]);
		sort(rv.begin(),rv.end(),cmpy);
		int t2=0;
		//cout<<rv.size()<<endl;
		while(t2<rv.size())
		{
			pr.clear(); pr.push_back(rv[t2++]);
			while(t2<rv.size() && y[rv[t2]]==y[rv[t2-1]]) pr.push_back(rv[t2++]);
			sort(pr.begin(),pr.end(),cmpz);
			//cout<<"PRAVVA "<<pr.size()<<endl;
			for(int i=0;i<pr.size();i++) if(!mtc[pr[i]])
			{
				int k=i+1;
				while(k<pr.size() && mtc[pr[k]]) k++;
				if(k!=pr.size()) {cout<<pr[i]<<" "<<pr[k]<<endl; mtc[pr[i]]=mtc[pr[k]]=true;}
				i=k;
			}
		}
		for(int i=0;i<rv.size();i++) if(!mtc[rv[i]])
		{
			int k=i+1;
			while(k<rv.size() && mtc[rv[k]]) k++;
			if(k!=rv.size()) {cout<<rv[i]<<" "<<rv[k]<<endl; mtc[rv[i]]=mtc[rv[k]]=true;}
			i=k;
		}
	}
	for(int i=0;i<sp.size();i++) if(!mtc[sp[i]])
	{
		int k=i+1;
		while(k<sp.size() && mtc[sp[k]]) k++;
		if(k!=sp.size()) cout<<sp[i]<<" "<<sp[k]<<endl;
		i=k;
	}
}