#include <iostream>
using namespace std;

int cnt[1000001];
int cl[1000001];
int N;

int main()
{
	ios::sync_with_stdio(0);
	int c;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> c;
		cnt[c]++;
	}
	int best = 0;
	int cur;
	for(int i=1000000;i>0;i--)
	{
		cur = 0;
		for(int j=i+i;j<=1000000;j+=i)
			cur = max(cur,cl[j]);
		cl[i] = cur + cnt[i];
	}
	cout << cl[1] << '\n';
}