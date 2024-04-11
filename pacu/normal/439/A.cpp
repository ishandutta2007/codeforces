#include <iostream>
using namespace std;

int jokes()
{
	int nSongs;
	int lEvent;
	int len;
	int cJokes = 0;
	cin >> nSongs >> lEvent;
	for(int i=0;i<nSongs;i++)
	{
		cin >> len;
		if(i<(nSongs-1))
		{
			len += 10;
			cJokes += 2;
		}
		if(len>lEvent) return -1;
		lEvent -= len;
	}
	return cJokes + (lEvent/5);
}

int main()
{
	cout << jokes() << endl;
}