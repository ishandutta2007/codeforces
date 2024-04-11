#include <iostream>
#include <string>
using namespace std;

#define MOD 1000000007
#define B 26

string p;

long long pw[1000001];
long long pref[1000001];
long long suf[1000001];
int N,PS;
bool badDif[1000001];

void comp()
{
	pw[0] = 1;
	for(int i=1;i<=PS;i++)
		pw[i] = (pw[i-1]*B)%MOD;
	pref[0] = (p[0]-'a');
	for(int i=1;i<PS;i++)
		pref[i] = (pref[i-1]+(p[i]-'a')*pw[i])%MOD;
	suf[PS-1] = (p[PS-1]-'a');
	for(int i=(PS-2);i>=0;i--)
		suf[i] = (suf[i+1]*B+(p[i]-'a'))%MOD;
	for(int i=0;i<PS;i++)
	{
		if(suf[i]==pref[PS-1-i]) badDif[i] = 0;
		else badDif[i] = 1;
	}
	for(int i=PS;i<N;i++)
		badDif[i] = 0;
}

int cloc[1000000];

int main()
{
	int M;
	cin >> N >> M >> p;
	PS = p.size();
	comp();
	for(int i=0;i<M;i++)
	{
		cin >> cloc[i];
		cloc[i]--;
	}
	for(int i=1;i<M;i++)
	{
		if(badDif[cloc[i]-cloc[i-1]])
		{
			cout << 0 << "\n";
			return 0;
		}
	}
	int j = -1;
	long long ans = 1;
	for(int i=0;i<N;i++)
	{
		if((j<=(M-2))&&(cloc[j+1]<=i)) j++;
		if((j==-1)||((cloc[j]+PS-1)<i)) ans = (ans*26)%MOD;
	}
	cout << ans << "\n";
}