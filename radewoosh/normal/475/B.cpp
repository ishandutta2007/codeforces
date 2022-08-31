#include <iostream>
#include <cstdio>
using namespace std;

int n, m;
string poz, pio;

int main()
{
	scanf("%d%d", &n, &m);
	cin >> poz >> pio;
	if ((poz[0]=='<' && poz[n-1]=='>' && pio[0]=='v' && pio[m-1]=='^') || (poz[0]=='>' && poz[n-1]=='<' && pio[0]=='^' && pio[m-1]=='v'))
	printf("YES");
	else
	printf("NO");
	return 0;
}