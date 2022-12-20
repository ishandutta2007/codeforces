#include <iostream>
#include <iomanip>
using namespace std;

int p[100000];
int N;
int sz[100000];
double t[100000];

int main()
{
	cin >> N;
	for(int i=1;i<N;i++)
	{
		cin >> p[i];
		p[i]--;
	}
	for(int i=0;i<N;i++)
		sz[i] = 1;
	for(int i=N-1;i>0;i--)
		sz[p[i]] += sz[i];
	t[0] = 1.0;
	for(int i=1;i<N;i++)
		t[i] = t[p[i]]+1.0+(sz[p[i]]-1-sz[i])/2.0;
	cout << setprecision(9);
	for(int i=0;i<N;i++)
		cout << t[i] << ' ';
	cout << '\n';
}