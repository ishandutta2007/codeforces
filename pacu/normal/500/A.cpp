#include <iostream>
using namespace std;
int A[30000];
bool here[30000];
int main()
{
	int N,t;
	cin >> N >> t;
	for(int i=0;i<(N-1);i++)
	{
		cin >> A[i];
		here[i] = 0;
	}
	t--;
	here[0] = 1;
	for(int i=0;i<t;i++)
	{
		if(!here[i])
			continue;
		here[i+A[i]] = 1;
	}
	if(here[t])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}