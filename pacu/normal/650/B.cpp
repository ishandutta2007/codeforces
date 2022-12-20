#include <iostream>
using namespace std;

long long N,A,B,T;
char c[500001];
long long sLeft[500001];
long long sRight[500001];

int main()
{
	cin >> N >> A >> B >> T;
	cin >> c;
	sLeft[0] = B*(c[0]=='w') + 1;
	long long ans = 0;
	for(int i=1;i<N;i++)
		sLeft[i] = sLeft[i-1] + A + B*(c[i]=='w') + 1;
	sRight[N-1] = A + B*(c[N-1]=='w') + 1;
	for(int i=N-2;i>=0;i--)
		sRight[i] = sRight[i+1] + A + B*(c[i]=='w') + 1;
	int j = 0;
	for(int i=0;i<N;i++)
	{
		while(j<N && sLeft[i] + sRight[j] + A*i > T) j++;
		//cout << i << ": " << j << "(" << sLeft[i] << ',' << sRight[j] << '\n';
		if(j<N)
			ans = max(ans,i+1+N-j);
	}
	j = 0;
	for(int i=0;i<N;i++)
	{
		while(j<N && sLeft[i] + sRight[j] + A*(N-j) > T) j++;
		if(j<N)
			ans = max(ans,i+1+N-j);
	}
	for(int i=0;i<N;i++)
		if(sLeft[i]<=T) ans = max(ans,i+1LL);
	cout << min(N,ans) << '\n';
}