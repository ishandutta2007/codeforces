#include <bits/stdc++.h>

using namespace std;

int t;

int main()
{
	ios::sync_with_stdio(false); 
	cin >> t;
	while(t--)
	{
		int temp = 0 , sum = 0 , x;
		cin >> x;
		while(sum < x)
		{
			sum += temp + 1;
			temp++;
		}
		if(sum - 1 == x)
			temp++;
		cout << temp << endl;
	}
	return 0;
}