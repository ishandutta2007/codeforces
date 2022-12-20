#include <iostream>
using namespace std;

struct road
{
	long long a,b,c;
};

bool side(road r,long long x,long long y)
{
	return (r.a*x+r.b*y+r.c)>0;
}

int main()
{
	long long x,y;
	long long ux,uy;
	road A[300];
	int N;
	cin >> x >> y;
	cin >> ux >> uy;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i].a >> A[i].b >> A[i].c;
	int cnt = 0;
	for(int i=0;i<N;i++)
		if(side(A[i],x,y) != side(A[i],ux,uy))
			cnt++;
	cout << cnt << endl;
	return 0;
}