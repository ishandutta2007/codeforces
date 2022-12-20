#include <iostream>
#include <algorithm>
using namespace std;

int N,B;
int d[200000],t[200000];
long long tAns[200000];

int que[200000];
int back,top;

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> B;
	long long tServ = 0;
	back = 0, top = 0;
	for(int i=0;i<N;i++)
	{
		cin >> t[i] >> d[i];
		while(tServ <= t[i] && back<top)
		{
			tServ += d[que[back]];
			tAns[que[back]] = tServ;
			back++;
		}
		if(tServ < t[i]) tServ = t[i];
		if(top-back < B)
			que[top++] = i;
		else
			tAns[i] = -1;
	}
	while(back<top)
	{
		tServ += d[que[back]];
		tAns[que[back]] = tServ;
		back++;		
	}
	for(int i=0;i<N;i++)
		cout << tAns[i] << ' ';
	cout << '\n';
}