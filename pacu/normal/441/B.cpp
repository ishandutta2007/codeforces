#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Tree
{
	int dayRipe;
	int val;
};
bool cmp(Tree a,Tree b)
{
	return a.dayRipe<b.dayRipe;
}

int main()
{
	int N,V;
	int day,iTree;
	int a,b;
	int cLeft;
	vector<Tree> trees;
	Tree t;
	int count = 0;
	cin >> N >> V;
	for(iTree=0;iTree<N;iTree++)
	{
		cin >> a >> b;
		t.dayRipe = a;
		t.val = b;
		trees.push_back(t);
	}
	sort(trees.begin(),trees.end(),cmp);
	for(iTree=0,day=1,cLeft=V;iTree<N;iTree++)
	{
		a = trees[iTree].dayRipe;
		b = trees[iTree].val;
		if(day>(a+1)) continue;
		while(day<a)
		{
			day++;
			cLeft = V;
		}
		int tooMany  = 0;
		while(b>=cLeft)
		{
			b -= cLeft;
			count += cLeft;
			day++;
			cLeft = V;
			if(day>(a+1))
			{
				tooMany = 1;
				break;
			}
		}
		if(tooMany) continue;
		cLeft -= b;
		count += b;
	}
	cout << count << endl;
}