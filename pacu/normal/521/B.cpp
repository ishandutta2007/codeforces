#include <iostream>
#include <set>
#include <map>
using namespace std;

pair<int,int> A[100000];

int main()
{
	int M;
	map<pair<int,int>, int> mp;
	set<int> sFree;
	cin >> M;
	for(int i=0;i<M;i++)
	{
		cin >> A[i].first >> A[i].second;
		mp[A[i]] = i+1;
	}
	for(int i=0;i<M;i++)
	{
		bool isFree = 1;
		bool n1 = mp.find(make_pair(A[i].first-1,A[i].second))!=mp.end();
		bool n2 = mp.find(make_pair(A[i].first-2,A[i].second))!=mp.end();
		bool p2 = mp.find(make_pair(A[i].first+2,A[i].second))!=mp.end();
		bool p1 = mp.find(make_pair(A[i].first+1,A[i].second))!=mp.end();
		if(mp.find(make_pair(A[i].first-1,A[i].second+1))!=mp.end())
			if(!(n1||n2)) isFree = 0;
		if(mp.find(make_pair(A[i].first,A[i].second+1))!=mp.end())
			if(!(n1||p1)) isFree = 0;
		if(mp.find(make_pair(A[i].first+1,A[i].second+1))!=mp.end())
			if(!(p1||p2)) isFree = 0;
		if(isFree)
			sFree.insert(i);
	}
	long long ans = 0;
	set<int>::iterator it;
	int dx[] = {-1,0,1,-2,-1,1,2};
	int dy[] = {-1,-1,-1,0,0,0,0};
	int a,b;
	bool isFree,n1,n2,p2,p1;
	int nxt;
	map<pair<int,int>, int>::iterator mit;
	for(int i=0;i<M;i++)
	{
		int cur;
		if(i%2)
			cur = *sFree.begin();
		else
		{
			it = sFree.end();
			it--;
			cur = *it;
		}
		ans = (M*ans + cur)%1000000009;
		mp.erase(A[cur]);
		sFree.erase(cur);
		for(int d=0;d<7;d++)
		{
			a = A[cur].first+dx[d];
			b = A[cur].second+dy[d];
			mit = mp.find(make_pair(a,b));
			if(mit==mp.end())
				continue;
			nxt = mit->second - 1;
			if(sFree.find(nxt)!=sFree.end())
				sFree.erase(nxt);
			isFree = 1;
			n1 = mp.find(make_pair(a-1,b))!=mp.end();
			n2 = mp.find(make_pair(a-2,b))!=mp.end();
			p2 = mp.find(make_pair(a+2,b))!=mp.end();
			p1 = mp.find(make_pair(a+1,b))!=mp.end();
			if(mp.find(make_pair(a-1,b+1))!=mp.end())
				if(!(n1||n2)) isFree = 0;
			if(mp.find(make_pair(a,b+1))!=mp.end())
				if(!(n1||p1)) isFree = 0;
			if(mp.find(make_pair(a+1,b+1))!=mp.end())
				if(!(p1||p2)) isFree = 0;
			if(isFree)
				sFree.insert(nxt);
		}
	}
	cout << ans << endl;
	return 0;
}