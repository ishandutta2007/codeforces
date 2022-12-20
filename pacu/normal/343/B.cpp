#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

char A[100001];
char S[100000];

int main()
{
	cin >> A;
	int N = strlen(A);
	int c = 0;
	for(int i=0;i<N;i++)
	{
		S[c++] = A[i];
		while((c>1)&&(S[c-1]==S[c-2]))
			c-=2;
	}
	if(c==0) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}