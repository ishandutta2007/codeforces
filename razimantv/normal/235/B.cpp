# include <cstdio>
# include <iostream>
# include <cmath>
# include <vector>
# include <set>
# include <algorithm>
# include <queue>

using namespace std;

int main()
{
	int N;
	cin>>N;

	double p,A=0,B=0,C=0,D=0,E=0;

	cin>>p;
	A=1;
	B=1+2*p;
	C=p;
	D=0;
	E=C;

	for(int i=1;i<N;i++)
	{
		cin>>p;

		D=(1-p)*E+p*D;
		C=p*(C+B);
		B=(1-p)+p*(B+2*A);
		A=(1-p)+p*A;
		E=D+C;
	}

	printf("%.9lE\n",E);

	return 0;
}