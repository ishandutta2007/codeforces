#include <iostream>
using namespace std;

long long p[50], t[50];
int N,C;

int main()
{
	cin >> N >> C;
	for(int i=0;i<N;i++)
		cin >> p[i];
	for(int i=0;i<N;i++)
		cin >> t[i];
	long long sm = 0;
	int tm = 0;
	for(int i=0;i<N;i++)
	{
		tm += t[i];
		sm += max(0LL,p[i]-C*tm);
	}
	tm = 0;
	for(int i=N-1;i>=0;i--)
	{
		tm += t[i];
		sm -= max(0LL,p[i]-C*tm);
	}
	if(sm > 0) cout << "Limak\n";
	else if(sm < 0) cout << "Radewoosh\n";
	else cout << "Tie\n";
}