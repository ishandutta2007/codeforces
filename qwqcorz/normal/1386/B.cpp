#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const long double pi=acos(-1.L);
const long double eps=1e-10L;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int cmp(long double x,long double y)
{
	if (abs(x-y)<eps) return 0;
	return x<y?-1:1;
}
struct comp
{
	bool operator ()(const long double &a,const long double &b)const
	{
		return cmp(a,b)<0;
	}
};
pair<long double,long double>a[N];
map<long double,int,comp>mp;
multiset<long double,comp>S;
void ins(long double ang)
{
	if (mp.size()==1) return;
	auto L=mp.find(ang),R=L;
	if (L==mp.begin()) L=prev(mp.end());
				  else L--;
	if (++R==mp.end()) R=mp.begin();
	long double ang1=ang-L->first,ang2=R->first-ang,ang3=R->first-L->first;
	if (cmp(ang1,0)<0) ang1+=pi*2;
	if (cmp(ang2,0)<0) ang2+=pi*2;
	if (cmp(ang3,0)<0) ang3+=pi*2;
	if (mp.size()>2) S.erase(ang3);
	S.insert(ang1);
	S.insert(ang2);
//	printf("+%lf\n",ang1);
//	printf("+%lf\n",ang2);
//	printf("-%lf\n",ang3);
}
void era(long double ang)
{
	if (mp.size()==1) return mp.erase(mp.find(ang)),void();
	auto L=mp.find(ang),R=L;
	if (L==mp.begin()) L=prev(mp.end());
				  else L--;
	if (++R==mp.end()) R=mp.begin();
	long double ang1=ang-L->first,ang2=R->first-ang,ang3=R->first-L->first;
	if (cmp(ang1,0)<0) ang1+=pi*2;
	if (cmp(ang2,0)<0) ang2+=pi*2;
	if (cmp(ang3,0)<0) ang3+=pi*2;
	S.erase(ang1);
	S.erase(ang2);
	if (mp.size()>2) S.insert(ang3);
	mp.erase(mp.find(ang));
//	printf("-%lf\n",ang1);
//	printf("-%lf\n",ang2);
//	printf("+%lf\n",ang3);
}

signed main()
{
	long double x=read(),y=read(),z=read(),u=x/(x+y+z),v=y/(x+y+z);
	int cnt=0,Q=read(),tot1=0,t1=0,t2=0; ll tot2=0;
//	printf("%lf,%lf\n",u,v);
	for (int i=1;i<=Q;i++)
	{
		char c=getchar();
		while (c!='A'&&c!='R') c=getchar();
		if (c=='A')
		{
			long double x=read(),y=read(),z=read(),p=x/(x+y+z),q=y/(x+y+z);
			a[++cnt]={p,q};
//			printf("%lf,%lf\n",p,q);
			if (cmp(p,u)==0&&cmp(q,v)==0) tot1++;
			else
			{
				long double ang=atan2(q-v,p-u);
				long double ang2=cmp(ang,0)>=0?ang-pi:ang+pi;
				if (q==v)
				{
					t1+=cmp(p,u)<0;
					t2+=cmp(p,u)>0;
				}
				else if (mp.count(ang2)) tot2+=mp[ang2];
				if (++mp[ang]) ins(ang);
//				printf("%lf %lf\n",ang,ang2);
			}
		}
		else
		{
			auto [p,q]=a[read()];
//			printf("%lf,%lf\n",p,q);
			if (cmp(p,u)==0&&cmp(q,v)==0) tot1--;
			else
			{
				long double ang=atan2(q-v,p-u);
				long double ang2=cmp(ang,0)>=0?ang-pi:ang+pi;
				if (q==v)
				{
					t1-=cmp(p,u)<0;
					t2-=cmp(p,u)>0;
				}
				else if (mp.count(ang2)) tot2-=mp[ang2];
				if (!--mp[ang]) era(ang);
//				printf("%lf %lf\n",ang,ang2);
			}
		}
//		print(tot2);
		if (tot1) puts("1");
		else if (tot2||t1&&t2) puts("2");
		else if (!S.empty()&&cmp(*S.rbegin(),pi)<=0) puts("3");
		else puts("0");
	}
	
	return 0;
}