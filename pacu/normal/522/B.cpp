#include <iostream>
using namespace std;

int w[200000];
int h[200000];
int main()
{
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> w[i] >> h[i];
	int mxh = 0,mxh2 = 0;
	for(int i=0;i<N;i++)
	{
		if(h[i] > mxh)
		{
			mxh2 = mxh;
			mxh = h[i];
		}
		else if(h[i] > mxh2)
			mxh2 = h[i];
	}
	int wt = 0;
	for(int i=0;i<N;i++)
		wt += w[i];
	int curh;
	for(int i=0;i<N;i++)
	{
		if(h[i] != mxh) cout << mxh*(wt-w[i]) << " ";
		else cout << mxh2*(wt-w[i]) << " ";
	}
	cout << "\n";
	return 0;
}