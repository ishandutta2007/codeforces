#include <iostream>
using namespace std;

int main()
{
	int N,bx;
	long long b = 0;
	cin >> N >> bx;
	int tmp;
	for(int i=0;i<N;i++)
	{
		cin >> tmp;
		b = bx*b + tmp;
	}
	int M,by;
	long long c = 0;
	cin >> M >> by;
	for(int i=0;i<M;i++)
	{
		cin >> tmp;
		c = by*c + tmp;
	}
	if(b < c) cout << "<\n";
	else if(b>c) cout << ">\n";
	else cout << "=\n";
}