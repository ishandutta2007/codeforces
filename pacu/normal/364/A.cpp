#include <iostream>
#include <string>
using namespace std;

long long occ[36001];
int sm[4001];
string s;
int a;

int main()
{
	cin >> a >> s;
	sm[0] = 0;
	long long N = s.size();
	for(int i=1;i<=N;i++)
		sm[i] = sm[i-1] + (s[i-1]-'0');
	int tot = 0;
	for(int i=0;i<=N;i++)
		for(int j=0;j<i;j++)
			occ[sm[i]-sm[j]]++,tot++;
	long long ans = 0;
	if(a==0)
		ans = occ[0]*(2*tot-occ[0]);
	else
	{
		for(int i=1;i<=36000;i++)
			if(!(a%i))
				if((a/i)<=36000)
					ans += occ[i]*occ[a/i];
	}
	cout << ans << endl;
}