#include <bits/stdc++.h>
#define MAXN 1007
using namespace std;
map<long long,int> m;
long long a[MAXN],p[MAXN],br[MAXN];
bool db[MAXN],ob[MAXN];
bool stepen(long long x,long long y)
{
	if(y==1) return true;
	if(y%x!=0) return false;
	return stepen(x,y/x);
}
bool prime(long long x)
{
	for(long long i=2;i*i<=x;i++) if(x%i==0) return false;
	return true;
}
long long fp(long long x)
{
	if(x<=1000000000 && prime(x)) return x;
	for(int i=2;i<=100;i++) if(stepen(i,x)) 
	{
		if(!prime(i)) return 0;
		return i;
	}
	for(int i=10;i>=2;i--)
	{
		long long y=round(pow(x,1.0/(double)i));
		for(int j=max(2LL,y-2);j<=y+2;j++) if(stepen(j,x)) 
		{
			if(!prime(j)) return 0;
			return j;
		}
	}
	return 0;
}
vector<long long> pr;
vector<long long> fk(long long x)
{
	vector<long long> sol,em;
	for(int i=0;i<pr.size();i++) if(x%pr[i]==0)
	{
		sol.push_back(pr[i]);
		while(x%pr[i]==0) x/=pr[i];
	}
	if(x!=1) return em;
	return sol;
}
int main()
{
	int n,k,z=0; cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
	{
		long long x=fp(a[i]);
		p[i]=x;
		if(x==0 || m[x]==2) continue;
		m[x]++;
		if(m[x]==2) pr.push_back(x);
	}
	z=pr.size();
	int t=0;
	for(int i=0;i<pr.size();i++) for(int j=0;j<n;j++) if(p[j]==pr[i] && m[pr[i]]) {ob[j]=true; m[pr[i]]--;}
	for(int i=0;i<n;i++) if(!ob[i])
	{
		vector<long long> v=fk(a[i]);
		br[i]=v.size();
		db[i]=(v.size()>0);
		if(v.size()>0) t++;
	}
	if(2*z+t<k) {printf("0"); return 0;}
	if(k>=2*z)
	{
		int l=k-2*z;
		for(int i=0;i<n;i++) if(ob[i] || (db[i] && l>0))
		{
			if(!ob[i]) l--;
			printf("%lld ",a[i]);
		}
	}
	if(k<2*z)
	{
		if(t==0 && (k&1)) {printf("0"); return 0;}
		set<long long> bp;
		int mn=1000000000,mnd;
		for(int i=0;i<n;i++) if(!ob[i] && db[i]) if(br[i]<mn) {mn=br[i]; mnd=i;}
		if(mn>k/2 && (k&1)) {printf("0"); return 0;}
		if(k&1)
		{
			vector<long long> v=fk(a[mnd]);
			for(int i=0;i<v.size();i++) bp.insert(v[i]);
		}
		for(int i=0;i<pr.size();i++) if(bp.find(pr[i])==bp.end() && bp.size()<k/2) bp.insert(pr[i]);
		if(!(k&1)) mnd=-1;
		for(int i=0;i<n;i++) if((ob[i] && bp.find(p[i])!=bp.end()) || i==mnd) printf("%lld ",a[i]);
	}
}