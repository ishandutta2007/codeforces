#include<bits/stdc++.h>
#define ll long long
using namespace std;
const double N=1e5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct point
{
	double x,y;
	bool operator ==(const point &a)const{return x==a.x&&y==a.y;}
	point operator -(point a){return (point){x-a.x,y-a.y};}
	double operator *(point a){return x*a.y-a.x*y;}
	double len(){return sqrt(x*x+y*y);}
};
vector<point>get(vector<point>&p)
{
	vector<point>s1,s2;
	int n1=0,n2=0;
	sort(p.begin(),p.end(),[&](point a,point b){
		return a.x==b.x?a.y<b.y:a.x<b.x;
	});
	for (auto i:p)
	{
		while (n1>1&&(s1[n1-1]-s1[n1-2])*(i-s1[n1-1])>=0) s1.pop_back(),n1--;
		s1.push_back(i),n1++;
	}
	for (auto i:p)
	{
		while (n2>1&&(s2[n2-1]-s2[n2-2])*(i-s2[n2-1])<=0) s2.pop_back(),n2--;
		s2.push_back(i),n2++;
	}
//	for (auto i:s1) print(i.x,','),print(i.y);;puts("");
//	for (auto i:s2) print(i.x,','),print(i.y);;puts("");
	if (!s1.empty()&&s1[0]==s2[0]) s1.erase(s1.begin());
	if (!s1.empty()&&s1.back()==s2.back()) s1.pop_back();
	reverse(s1.begin(),s1.end());
	for (auto i:s1) s2.push_back(i);
//	for (auto i:s2) print(i.x,','),print(i.y);;puts("");
	return s2;
}

signed main()
{
	vector<point>p;
	int n=read();
	for (int i=1;i<=n;i++)
	{
		double x=read(),y=read(),v=read();
		if (x-v>=0) p.push_back((point){x-v,y});
		else
		{
			double len=v-x;
			p.push_back((point){0,max(y-len,0.)});
			p.push_back((point){0,min(y+len,N)});
		}
		if (y-v>=0) p.push_back((point){x,y-v});
		else
		{
			double len=v-y;
			p.push_back((point){max(x-len,0.),0});
			p.push_back((point){min(x+len,N),0});
		}
		if (x+v<=N) p.push_back((point){x+v,y});
		else
		{
			double len=x+v-N;
			p.push_back((point){N,max(y-len,0.)});
			p.push_back((point){N,min(y+len,N)});
		}
		if (y+v<=N) p.push_back((point){x,y+v});
		else
		{
			double len=y+v-N;
			p.push_back((point){max(x-len,0.),N});
			p.push_back((point){min(x+len,N),N});
		}
	}
	auto a=get(p);
	int m=a.size(),id=-1;
	double ans=0;
	for (int i=0;i<m;i++)
	{
		auto A=a[i],B=a[(i+1)%m],C=a[(i+2)%m];
		double R=(A-B).len()*(B-C).len()*(C-A).len()/abs((B-A)*(C-A));
		if (R>ans) ans=R,id=i;
	}
	auto A=a[id],B=a[(id+1)%m],C=a[(id+2)%m];
	print(A.x,' '),print(A.y);
	print(B.x,' '),print(B.y);
	print(C.x,' '),print(C.y);
	
	return 0;
}