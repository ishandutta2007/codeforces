#include <iostream>
#include <string>
using namespace std;

int dist[100000];
string s;

int main()
{
	int N,P;
	cin >> N >> P >> s;
	P--;
	int tot = 0;
	for(int i=0;i<N;i++)
	{
		dist[i] = min(abs(s[i]-s[(N-1)-i]),26-abs(s[i]-s[(N-1)-i]));
		tot += dist[i];
	}
	tot /= 2;
	if(P>=(N/2))
		P = ((N-1)-P);
	if(1)
	{
		int ans = 0;
		int first;
		for(first=0;first<P;first++)
			if(dist[first])
				break;
		int last;
		for(last=((N-1)/2);last>P;last--)
			if(dist[last])
				break;
		ans = tot + abs(last-first) + min(P-first,last-P);
		cout << ans << endl;
	}
}