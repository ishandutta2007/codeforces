#include <iostream>
using namespace std;
int main()
{
	int n,m,a;
	long long ansN,ansM;
	cin >> n >> m >> a;
	ansN = n/a;
	if((a*ansN)<n) ansN++;
	ansM = m/a;
	if((a*ansM)<m) ansM++;
	cout << ansN*ansM << endl;
}