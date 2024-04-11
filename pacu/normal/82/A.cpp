#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	N--;
	int c=1;
	while(N>=5*c)
	{
		N -= 5*c;
		c += c;
	}
	N = N/c;
	if(N==0) cout << "Sheldon";
	if(N==1) cout << "Leonard";
	if(N==2) cout << "Penny";
	if(N==3) cout << "Rajesh";
	if(N==4) cout << "Howard";
	cout << endl;
}