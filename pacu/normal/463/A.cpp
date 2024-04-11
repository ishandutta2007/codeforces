#include <iostream>
using namespace std;

int main()
{
	int N,S;
	cin >> N >> S;
	int best = -1;
	int a,b;
	for(int i=0;i<N;i++)
	{
		cin >> a >> b;
		if((100*a+b)<=(100*S))
		{
			if(b==0)
				b = 100;
			best = max(best,(100-b)%100);
		}
	}
	cout << best << endl;
}