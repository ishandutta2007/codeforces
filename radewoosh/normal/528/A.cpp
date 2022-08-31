#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int w, h;
int n;
set < int > cie1;
set < int > cie2;
int ost1[1000007];
int ost2[1000007];
priority_queue < pair <int , pair <int,int> > > kol1;
priority_queue < pair <int , pair <int,int> > > kol2;

char p1[5];
int p2;
int dal;
long long jed=1;

int main()
{
	scanf("%d%d%d", &w, &h, &n);
	for (int i=0; i<=1000000; i++)
	{
		ost1[i]=-1;
		ost2[i]=-1;
	}
	ost1[w]=0;
	ost2[h]=0;
	cie1.insert(w);
	cie2.insert(h);
	kol1.push(make_pair(w, make_pair(0, w)));
	kol2.push(make_pair(h, make_pair(0, h)));
	for (int i=1; i<=n; i++)
	{
		scanf("%s%d", &p1, &p2);
		if (p1[0]=='V')
		{
			dal=*cie1.lower_bound(p2);
			kol1.push(make_pair(dal-p2, make_pair(p2, dal)));
			kol1.push(make_pair(p2-ost1[dal], make_pair(ost1[dal], p2)));
			cie1.insert(p2);
			ost1[p2]=ost1[dal];
			ost1[dal]=p2;
		}
		else
		{
			dal=*cie2.lower_bound(p2);
			kol2.push(make_pair(dal-p2, make_pair(p2, dal)));
			kol2.push(make_pair(p2-ost2[dal], make_pair(ost2[dal], p2)));
			cie2.insert(p2);
			ost2[p2]=ost2[dal];
			ost2[dal]=p2;
		}
		//for (int i=1; i<=w; i++)
		//{
		//	prnitf("");
		//}
		while(ost1[kol1.top().second.second]!=kol1.top().second.first)
		kol1.pop();
		while(ost2[kol2.top().second.second]!=kol2.top().second.first)
		kol2.pop();
		//printf("%d %d\n", kol1.top().second.first, kol1.top().second.second);
		//printf("%d %d\n", kol2.top().second.first, kol2.top().second.second);
		printf("%lld\n", jed * kol1.top().first * kol2.top().first);
	}
	return 0;
}