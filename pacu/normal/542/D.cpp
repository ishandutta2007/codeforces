#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<long long,int> M;
vector<long long> divi;

vector<pair<long long,long long> > pows;

long long A;

void check(long long d)
{
	if(d <= 2) return;
	d--;
	long long v;
	for(v=2;v*v<=d;v++)
	{
		if(!(d%v))
			break;
	}
	if(v*v > d) v = d;
	long long c = v;
	int i = 1;
	while(c < d)
		c *= v, i++;
	if(c == d)
	{
		pows.push_back(make_pair(v,d+1));
//		cout << v << ' ' << d+1 << '\n';
	}
}

int ways[7000][7000];	//diviisor #, prime #

int main()
{
	cin >> A;
	for(long long i=1;i*i<=A;i++)
	{
		if(!(A%i))
		{
			divi.push_back(i);
			if(i*i < A)
				divi.push_back(A/i);
		}
	}
	sort(divi.begin(),divi.end());
//	for(int i=0;i<divi.size();i++)
//		cout << divi[i] << ' ';
//	cout << '\n';
	for(int i=0;i<divi.size();i++)
		check(divi[i]);
	sort(pows.begin(),pows.end());
	for(int i=0;i<divi.size();i++)
		M[divi[i]] = i;
	int P = 1;
	for(int i=1;i<pows.size();i++)
		if(pows[i].first != pows[i-1].first)
			P++;
	for(int j=0;j<=P;j++)
		ways[0][j] = 1;
	for(int i=1;i<divi.size();i++)
	{
		int c = 1;
		for(int j=0;j<pows.size();j++)
		{
			if(j>0 && pows[j].first != pows[j-1].first)
			{
				c++;
				ways[i][c] = ways[i][c-1];
			}
			if(!(divi[i]%pows[j].second))
			{
				ways[i][c] += ways[M[divi[i]/pows[j].second]][c-1];
//				cout << divi[i] << ' ' << c << " from " << divi[i]/pows[j].second << ": " << ways[M[divi[i]/pows[j].second]][c-1] << " - " << ways[i][c] << '\n';
			}
		}
//		cout << ways[i][P] << '\n';
	}
	cout << ways[divi.size()-1][P] << '\n';
}