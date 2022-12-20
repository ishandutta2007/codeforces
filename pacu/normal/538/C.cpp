#include <iostream>
using namespace std;

int d[100000];
int h[100000];
int N,M;

int gg(int a)
{
	if(a<0) return -a;
	return a;
}

int main()
{
	cin >> N >> M;
	int best = 0;
	for(int i=0;i<M;i++)
	{
		cin >> d[i] >> h[i];
		best = max(best,h[i]);
	}
	best = max(best,h[0]+d[0]-1);
	best = max(best,h[M-1]+(N-d[M-1]));
	for(int i=0;i<(M-1);i++)
	{
		if(gg(h[i+1]-h[i])>(d[i+1]-d[i]))
		{
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		else if(gg(h[i+1]-h[i])==(d[i+1]-d[i]))
			continue;
		else
		{
			best = max(best,(h[i]+h[i+1]+(d[i+1]-d[i]))/2);
		}
	}
	cout << best << endl;
	return 0;
}