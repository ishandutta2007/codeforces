#include <iostream>
#include <map>
using namespace std;
map<int,int> used;
void printPair(int pairs,int sm)
{
	if(pairs==0)
		return;
	int a = 2;
	int b = 3;
	if(pairs==sm)
	{
		for(int i=0;i<pairs;i++)
		{
			while((used[a]>0)||(used[b]>0))
				a+=2,b+=2;
			cout << a << " " << b << " ";
			a+=2;
			b+=2;
		}
		return;
	}
	int curgcd = sm - (pairs-1);
	while((used[a*curgcd]>0)||(used[b*curgcd]>0))
	{
		a++,b++;
	}
	cout << a*curgcd << " " << b*curgcd << " ";
	used[a*curgcd]++;
	used[b*curgcd]++;
	printPair(pairs-1,sm-curgcd);
}


int main()
{
	int N,K,nPairs;
	cin >> N >> K;
	nPairs = N/2;
	if(nPairs>K)
	{
		cout << -1 << endl;
		return 0;
	}
	if((nPairs==0)&&(K!=0))
	{
		cout << -1 << endl;
		return 0;
	}
	printPair(nPairs,K);
	if(N%2)
		cout << 1 << endl;
}