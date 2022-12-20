#include <iostream>
using namespace std;

int x[1001],y[1001];
int N;

char dir(int i)
{
	int j = (i+1)%N;
	if(x[i]==x[j])
	{
		if(y[i] < y[j]) return 'N';
		else return 'S';
	}
	else
	{
		if(x[i] < x[j]) return 'E';
		else return 'W';
	}
}

bool dan(int i)
{
	char a = dir(i);
	char b = dir((i+1)%N);
	if(a=='N' && b=='W') return 1;
	if(a=='S' && b=='E') return 1;
	if(a=='E' && b=='N') return 1;
	if(a=='W' && b=='S') return 1;
	return 0;
}

int main()
{
	
	cin >> N;
	for(int i=0;i<=N;i++) cin >> x[i] >> y[i];
	int ans = 0;
	for(int i=0;i<N;i++) ans += dan(i);
	cout << ans << '\n';
}