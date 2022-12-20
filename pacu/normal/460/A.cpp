#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int count;
	int day;
	int M;
	cin >> count >> M;
	for(day=1;count>0;day++)
	{
		count--;
		if(!(day%M))
			count++;
	}
	cout << day-1 << endl;
}