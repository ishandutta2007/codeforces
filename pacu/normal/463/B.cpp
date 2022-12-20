#include <iostream>
using namespace std;

int main()
{
	int N;
	int curEnergy = 0;
	long long dol = 0;
	cin >> N;
	int prev = 0;
	int cur;
	for(int i=0;i<N;i++)
	{
		cin >> cur;
		if(prev>=cur)
			curEnergy += (prev-cur);
		else	//prev < cur
		{
			int negEnergy = min(curEnergy,cur-prev);
			curEnergy -= negEnergy;
			prev += negEnergy;
			dol += (cur-prev);
		}

		prev = cur;
	}
	cout << dol << endl;
}