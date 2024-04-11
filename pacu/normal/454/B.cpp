#include <iostream>
using namespace std;

int main()
{
	int N,val,prev;
	prev = 0;
	cin >> N;
	int count = 0;
	int last = -1;
	int first;
	for(int i=0;i<N;i++)
	{
		cin >> val;
		if(i==0) first = val;
		count += (val<prev);
		if(val<prev)
		{
			last = i-1;
		}
		prev = val;
	}
	if(count==0)
		cout << 0 << endl;
	else if((count>1)||(first<val))
		cout << -1 << endl;
	else
		cout << (N-1)-last << endl;
}