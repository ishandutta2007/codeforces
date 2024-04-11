#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > guest;

int main()
{
	int n;
	cin >> n;
	int d = 0;
	while((d*(d-1)) <= 2*n)
	{
		d++;
		guest.push_back(vector<int>());
	}
	d--;
	int c = 1;
	for(int i=0;i<d;i++)
		for(int j=(i+1);j<d;j++)
		{
			guest[i].push_back(c);
			guest[j].push_back(c);
			c++;
		}
	cout << d << endl;
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<guest[i].size();j++)
			cout << guest[i][j] << " ";
		cout << endl;
	}
}