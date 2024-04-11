#include <iostream>
using namespace std;

int pos[100001];
int neg[100001];
int N;

int main()
{
	cin >> N;
	int a,b;
	int c1 = 0;
	int c2 = 0;
	for(int i=0;i<N;i++)
	{
		cin >> a >> b;
		if(a>0) pos[a] = b,c1++;
		else neg[-a] = b,c2++;
	}
	int vis2 = c2;
	int vis1 = c2;
	while(vis1>c1)
		vis2--,vis1--;
	if(vis2<c2)
		vis2++;
	long long ans = 0;
	for(int i=0;i<=100000;i++)
	{
		if(pos[i]&&vis1)
		{
			ans += pos[i];
			vis1--;
		}
		if(neg[i]&&vis2)
		{
			ans += neg[i];
			vis2--;
		}
	}
	vis2 = c1;
	vis1 = c1;
	while(vis2>c2)
		vis2--,vis1--;
	if(vis1<c1)
		vis1++;
	long long ans2 = 0;
	for(int i=0;i<=100000;i++)
	{
		if(pos[i]&&vis1)
		{
			ans2 += pos[i];
			vis1--;
		}
		if(neg[i]&&vis2)
		{
			ans2 += neg[i];
			vis2--;
		}
	}
	cout << max(ans,ans2) << '\n';
}