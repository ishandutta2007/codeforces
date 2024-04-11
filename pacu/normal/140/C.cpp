#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
struct Ball
{
	int size;
	int num;
};
struct Triple
{
	int x,y,z;
};

bool operator<(Ball a,Ball b)
{
	if(a.num==b.num)
		return a.size>b.size;
	return a.num>b.num;
}

void order(Triple &a)
{
	int hx = max(max(a.x,a.y),a.z);
	int lx = min(min(a.x,a.y),a.z);
	int mx = min(max(min(a.x,a.y),a.z),max(min(a.x,a.z),a.y));
	a.x = hx;
	a.y = mx;
	a.z = lx;
}

int main()
{
	int N;
	int i;
	int v;
	int count;
	vector<int> aSizes;
	set<Ball> S;
	vector<Triple> ans;
	int setsize;
	Ball b;
	cin >> N;
	for(i=0;i<N;i++)
	{
		cin >> v;
		aSizes.push_back(v);
	}
	sort(aSizes.begin(),aSizes.end());
	count = 1;
	setsize = 0;
	for(i=1;i<=N;i++)
	{
		if((i<N)&&(aSizes[i]==aSizes[i-1]))
			count++;
		else
		{
			b.num = count;
			b.size = aSizes[i-1];
			S.insert(b);
			count = 1;
			setsize++;
		}
	}
	Triple sm;
	Triple cts;
	Ball a;
	while(1)
	{
		if(setsize<3)
			break;
		a = *S.begin();
		sm.x = a.size,cts.x = a.num;
		S.erase(S.begin());

		a = *S.begin();
		sm.y = a.size,cts.y = a.num;
		S.erase(S.begin());

		a = *S.begin();
		sm.z = a.size,cts.z = a.num;
		S.erase(S.begin());
		setsize -= 3;

		a.size = sm.x,a.num = cts.x-1;
		if(a.num)
		{
			S.insert(a);
			setsize++;
		}
		a.size = sm.y,a.num = cts.y-1;
		if(a.num)
		{
			S.insert(a);
			setsize++;
		}
		a.size = sm.z,a.num = cts.z-1;
		if(a.num)
		{
			S.insert(a);
			setsize++;
		}
		order(sm);
		ans.push_back(sm);
	}
	cout << ans.size() << endl;
	for(i=0;i<(ans.size());i++)
		cout << ans[i].x << " " << ans[i].y << " " << ans[i].z << endl;
}