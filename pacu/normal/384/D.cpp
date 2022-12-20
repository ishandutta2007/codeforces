#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct volc
{
	int x,y;
};

bool cmp(volc a,volc b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}

struct Interval
{
	int start,end;
};

volc V[100001];
int main()
{
	int N,M;
	cin >> N >> M;
	for(int i=0;i<M;i++)
		cin >> V[i].x >> V[i].y;
	V[M].x = N;
	V[M].y = N+1;
	M++;
	sort(V,V+M,cmp);

	vector<Interval> I;
	vector<Interval> nui;
	I.push_back(Interval());
	I[0].start = 1;
	I[0].end = 1;
	int prevX = 0;
	int i = 0;
	while(i<M)
	{
		int j = i;
		if(V[i].x > (prevX+1))
		{
			int top = I[0].start;
			I.clear();
			I.push_back(Interval());
			I[0].start = top;
			I[0].end = N;
		}
		prevX = V[i].x;
		nui.clear();
		int curInterval = 0;
		int yPrevVolc = 0;
		while((j<M)&&(V[j].x==V[i].x))
		{
			if((curInterval<I.size())&&(I[curInterval].start < V[j].y))
			{
				nui.push_back(Interval());
				nui[nui.size()-1].start = max(yPrevVolc+1,I[curInterval].start);
				nui[nui.size()-1].end = V[j].y - 1;
			}

			while((curInterval<I.size())&&(I[curInterval].end <= V[j].y))
				curInterval++;

			if(curInterval<I.size())
				I[curInterval].start = max(I[curInterval].start,V[j].y+1);

			yPrevVolc = V[j].y;
			j++;
		}
		if(curInterval < I.size())
		{
			nui.push_back(Interval());
			nui[nui.size()-1].start = max(yPrevVolc+1,I[curInterval].start);
			nui[nui.size()-1].end = N;
		}
		if(nui.size()==0)
		{
			cout << -1 << endl;
			return 0;
		}
		I.clear();
		for(int k=0;k<nui.size();k++)
			I.push_back(nui[k]);
		i = j;
	}
	if(I.size()==0)
		cout << -1 << endl;
	else if(I[I.size()-1].end==N)
		cout << 2*(N-1) << endl;
	else
		cout << -1 << endl;
}