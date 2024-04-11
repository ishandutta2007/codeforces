#include <iostream>
#include <set>
using namespace std;

int par[300000];
set<int> S;

int main()
{
	ios::sync_with_stdio(0);
	int N,M;
	cin >> N >> M;
	int a,b,x;
	set<int>::iterator it,it2;
	S.insert(-1);
	S.insert(1000000000);
	for(int i=0;i<N;i++)
		S.insert(i);
	for(int i=0;i<M;i++)
	{
		cin >> a >> b >> x;
		a--,b--,x--;
		it = S.find(x);
		for(it++;*it<=b;)
		{
			it2 = it++;
			par[*it2] = x+1;
			S.erase(it2);
		}
		it = S.find(x);
		for(it--;*it>=a;)
		{
			it2 = it--;
			par[*it2] = x+1;
			S.erase(it2);
		}
	}
	for(int i=0;i<N;i++)
		cout << par[i] << " ";
	cout << endl;
	return 0;
}