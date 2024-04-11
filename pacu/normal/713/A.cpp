#include <iostream>
#include <string>
using namespace std;

int nxt[2000000][2];
int sz[2000000];

int main()
{
	int N;
	char tp;
	string s;
	cin >> N;
	int C = 1;
	for(int i=0;i<N;i++)
	{
		cin >> tp >> s;
		while(s.size()<18)
			s = '0'+s;
		if(tp=='?')
		{
			int j = 0;
			int stop = 0;
			for(int c=s.size()-1;c>=0;c--)
			{
				int par = (s[c]-'0')%2;
				if(nxt[j][par]==0)
				{
					j = C;
					break;
				}
				j = nxt[j][par];
			}
			cout << sz[j] << '\n';
		}
		else
		{
			int dif = 1;
			if(tp=='-') dif = -1;
			int j = 0;
			for(int c=s.size()-1;c>=0;c--)
			{
				int par = (s[c]-'0')%2;
				if(nxt[j][par]==0)
					nxt[j][par] = C++;
				j = nxt[j][par];
			}
			sz[j]+=dif;
		}
	}
}