#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int cntx[100001];
int cnty[100001];
int cntz[100001];
int main()
{
	string s;
	cin >> s;
	cntx[0] = cnty[0] = cntz[0] = 0;
	for(int i=0;i<s.size();i++)
	{
		cntx[i+1] = cntx[i] + (s[i]=='x');
		cnty[i+1] = cnty[i] + (s[i]=='y');
		cntz[i+1] = cntz[i] + (s[i]=='z');
	}
	int M;
	int l,r;
	int cnt[3];
	cin >> M;
	for(int i=0;i<M;i++)
	{
		cin >> l >> r;
		cnt[0] = cntx[r]-cntx[l-1];
		cnt[1] = cnty[r]-cnty[l-1];
		cnt[2] = cntz[r]-cntz[l-1];
		sort(cnt,cnt+3);
		if((r+1-l)<3)
		{
			cout << "YES" << endl;
		}
		else if(((r+1-l)%3)==0)
		{
			if((cnt[0]==cnt[1])&&(cnt[1]==cnt[2]))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else if(((r+1-l)%3)==1)
		{
			if((cnt[0]==cnt[1])&&(cnt[1]==(cnt[2]-1)))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else if(((r+1-l)%3)==2)
		{
			if((cnt[0]==(cnt[1]-1))&&(cnt[1]==cnt[2]))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
}