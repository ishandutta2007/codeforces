#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define MAXN 500000

int N,Q;
int h[500000];
int lLen[500000],rLen[500000];

int a[500000],nval[500000],cid[500000],qLeft[500000],qRight[500000],ans[500000];

bool cmp(int x,int y)
{
	return a[x] < a[y];
}

int minVal[500000];
int maxVal[500000];
vector<int> lst[500000];

int binSearch(int low,int high,int v)
{
	if(low==high) return low;
	if(low+1==high)
	{
		if(minVal[high] < v) return high;
		return low;
	}
	int mid = (low+high)/2;
	if(minVal[mid] < v) return binSearch(mid,high,v);
	else return binSearch(low,mid-1,v);
}
int binSearch2(int low,int high,int v)
{
	if(low==high) return low;
	if(low+1==high)
	{
		if(maxVal[high] > v) return high;
		return low;
	}
	int mid = (low+high)/2;
	if(maxVal[mid] > v) return binSearch2(mid,high,v);
	else return binSearch2(low,mid-1,v);
}

int binSearch3(int low,int high,int v,int indx)
{
	if(low==high) return low;
	if(low+1==high)
	{
		if(h[lst[indx][low]] < v) return low;
		return high;
	}
	int mid = (low+high)/2;
	if(h[lst[indx][mid]] < v) return binSearch3(low,mid,v,indx);
	else return binSearch3(mid+1,high,v,indx);
}

int main()
{
	scanf("%d %d",&N,&Q);
	for(int i=0;i<N;i++)
		scanf("%d",&h[i+1]);
	h[0] = 0;
	h[N+1] = 1000000001;
	N += 2;
	for(int i=0;i<Q;i++)
	{
		scanf("%d %d",&a[i],&nval[i]);
		cid[i] = i;
	}
	sort(cid,cid+Q,cmp);
	int fq = 0;
	int mx = 0;
	minVal[0] = -1;
	for(int i=0;i<N;i++)
	{
		while(fq<Q && a[cid[fq]] < i) fq++;
		while(fq<Q && a[cid[fq]] == i)
		{
			qLeft[cid[fq]] = binSearch(0,mx,nval[cid[fq]]);
			fq++;
		}
		int j = binSearch(0,mx,h[i]);
		lLen[i] = j+1;
		if(j==mx)
		{
			mx++;
			minVal[j+1] = h[i];
		}
		else
			minVal[j+1] = h[i];
		lst[j+1].push_back(i);
	}
	int mx2 = 0;
	fq = Q-1;
	maxVal[0] = 1000000002;
	for(int i=N-1;i>=0;i--)
	{
		while(fq>=0 && a[cid[fq]] > i) fq--;
		while(fq>=0 && a[cid[fq]] == i)
		{
			qRight[cid[fq]] = binSearch2(0,mx2,nval[cid[fq]]);
			fq--;
		}
		int j = binSearch2(0,mx2,h[i]);
		rLen[i] = j+1;
		if(j==mx2)
		{
			mx2++;
			maxVal[j+1] = h[i];
		}
		else
			maxVal[j+1] = h[i];
	}
	//cout << '\n';
	set<int> needed;
	set<int>::iterator it,it2;
	for(int i=0;i<N;i++)
		needed.insert(i);
	for(int i=0;i<N;i++)
	{
		if(lst[mx-rLen[i]].size() == 0) continue;
		int fst = lst[mx-rLen[i]][binSearch3(0,lst[mx-rLen[i]].size()-1,h[i],mx-rLen[i])];
		if(h[fst] >= h[i]) continue;
		it = needed.upper_bound(fst);
		while(it != needed.end() && *it < i)
		{
			it2 = it++;
			needed.erase(it2);
		}
	}
	//cout << needed.size()-2 << '\n';
	for(int i=0;i<Q;i++)
	{
		int without = mx-1;
		if(needed.find(a[i])==needed.end()) without = mx;
		printf("%d\n",max(qLeft[i]+qRight[i]+1,without)-2);
	}
}