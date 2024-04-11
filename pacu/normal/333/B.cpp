#include <iostream>
using namespace std;

int N;
int B;

bool gx[1000];
bool gy[1000];

int main()
{
	cin >> N >> B;
	int x,y;
	for(int i=0;i<N;i++)
		gx[i] = gy[i] = 1;
	for(int i=0;i<B;i++)
	{
		cin >> x >> y;
		x--,y--;
		gx[x] = 0, gy[y] = 0;
	}
	int ans = 0;
	for(int i=1;i<N-1;i++)
	{
		if(2*i == N-1)
			if(gx[i] || gy[i]) ans++;
		if(2*i >= N-1)
			break;
		if(gx[i]) ans++;
		if(gx[N-1-i]) ans++;
		if(gy[i]) ans++;
		if(gy[N-1-i]) ans++;
	}
	cout << ans << '\n';
}