#include <iostream>
#include <string>
using namespace std;

bool iso[100][100];

int main()
{
	int N;
	cin >> N;
	string s;
	int i,j;
	for(i=0;i<N;i++)
	{
		cin >> s;
		for(j=0;j<N;j++)
			iso[i][j] = (s[j]=='o');
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			int ct = 0;
			if(i>0) ct += iso[i-1][j];
			if(j>0) ct += iso[i][j-1];
			if(i<(N-1)) ct += iso[i+1][j];
			if(j<(N-1)) ct += iso[i][j+1];
			if(ct%2)
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
}