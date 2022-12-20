#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> head[200000];
int hid[200000];
set<int> sDif;
int N;

void merge(int a,int b)
{
	a = hid[a];
	b = hid[b];
	if(a == b) return;
	if(head[a].size() > head[b].size())
		swap(a,b);
	int c;
	for(int j=head[a].size()-1;j>=0;j--)
	{
		c = head[a][j];
		if(c > 0 && hid[c-1] == b)
			sDif.erase(c-1);
		if(c < N-1 && hid[c+1] == b)
			sDif.erase(c);
	}
	for(int j=head[a].size()-1;j>=0;j--)
	{
		c = head[a][j];
		hid[c] = b;
		head[b].push_back(c);
	}
	head[a].clear();
}

void mergeAll(int a,int b)
{
	set<int>::iterator it;
	int c;
	while(1)
	{
		it = sDif.lower_bound(a);
		if(it == sDif.end() || (*it) >= b)
			break;
		c = *it;
		merge(c,c+1);
	}
}

int main()
{
	int Q;
	cin >> N >> Q;
	for(int i=0;i<N;i++)
	{
		hid[i] = i;
		if(i<N-1)
			sDif.insert(i);
		head[i].push_back(i);
	}
	int tp,x,y;
	for(int i=0;i<Q;i++)
	{
		cin >> tp >> x >> y;
		x--,y--;
		if(tp == 1) merge(x,y);
		else if(tp == 2) mergeAll(x,y);
		else
		{
			if(hid[x] == hid[y]) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}