#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	string orig;
	string cur;
	string best;
	cin >> N >> orig;
	best = orig;
	for(int add=0;add<10;add++)
	{
		for(int shift=0;shift<N;shift++)
		{
			cur.clear();
			for(int i=0;i<N;i++)
				cur.push_back((char)((orig[(i+shift)%N]+add)%10)+'0');
			if(cur < best)
				best = cur;
		}
	}
	cout << best << endl;
}