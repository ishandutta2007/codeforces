#include <iostream>
#include <string>
using namespace std;

int N;
int p[500000];
string s;
long long l[500000],r[500000];

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> p[i];
	cin >> s;
	l[0] = p[0]*(s[0]=='A');
	for(int i=1;i<N;i++)
		l[i] = l[i-1] + p[i]*(s[i]=='A');
	r[N-1] = p[N-1]*(s[N-1]=='B');
	for(int i=N-2;i>=0;i--)
		r[i] = r[i+1] + p[i]*(s[i]=='B');
	long long best = max(r[0],l[N-1]);
	for(int i=0;i<N-1;i++)
		best = max(best,max(l[i]+r[i+1],r[0]+l[N-1]-l[i]-r[i+1]));
	cout << best << '\n';
}