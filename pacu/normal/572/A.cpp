#include <iostream>
using namespace std;

int nA,nB;
int k,m;

int A[100000],B[100000];

int main()
{
	cin >> nA >> nB >> k >> m;
	for(int i=0;i<nA;i++) cin >> A[i];
	for(int j=0;j<nB;j++) cin >> B[j];
	if(A[k-1] < B[nB-m]) cout << "YES\n";
	else cout << "NO\n";
}