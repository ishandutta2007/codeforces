#include <iostream>
#include <algorithm>

using namespace std;

int n;
string a , b;
int sum = 0 , max1 = 0 , min1 = 0;

int main()
{
	cin >> n;
	cin >> a >> b; 
	for(int i = 0; i < n; i++)
	{
		sum += a[i] - b[i];
		max1 = max(max1 , sum);
		min1 = min(min1 , sum); 
	}
	if(sum != 0)
		cout << -1 << endl;
	else
		cout << max1 - min1 << endl; 
	return 0;
}