#include <iostream>
using namespace std;

int N,M;
int cid[100000],cyc[100000];
void init()
{
	for(int i=0;i<N;i++)
		cid[i] = i;
}
int find(int i)
{
	if(cid[i]==i) return i;
	cid[i] = find(cid[i]);
	return cid[i];
}
void join(int i,int j)
{
	i = find(i), j = find(j);
	if(i==j) cyc[j] = 1;
	else cid[i] = j, cyc[j] = (cyc[j]||cyc[i]);
}

int main()
{
	cin >> N >> M;
	int a,b;
	init();
	for(int i=0;i<M;i++)
	{
		cin >> a >> b;
		a--,b--;
		join(a,b);
	}
	int cnt = 0;
	for(int i=0;i<N;i++)
		if(find(i)==i && cyc[i]==0)
		{
			cnt++;
		}
	cout << cnt << '\n';
}