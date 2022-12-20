#include <iostream>
#include <algorithm>
using namespace std;

int N,L,A;

int t[100000];
int l[100000];

int main()
{
	cin >> N >> L >> A;
	for(int i=0;i<N;i++)
		cin >> t[i] >> l[i];
	int cnt = t[0]/A;
	for(int i=1;i<N;i++)
		cnt += (t[i] - t[i-1] - l[i-1])/A;
	cnt += (L - t[N-1] - l[N-1])/A;
	cout << cnt << '\n';
}