#include <iostream>
using namespace std;

int main()
{
	int N,M;
	int low,high,c;
	cin >> N >> M;
	high = 0;
	for(int i=0;i<N;i++)
	{
		low = 1000000000;
		for(int j=0;j<M;j++)
		{
			cin >> c;
			low = min(low,c);
		}
		high = max(high,low);
	}
	cout << high << '\n';
}