#include <iostream>
#include <string>
#include <vector>
using namespace std;

void swap(string &s,int i,int j)
{
	int k = s[i];
	s[i] = s[j];
	s[j] = k;
}
void gbest(string &s,int begin,int k)
{
	if(k==0) return;
	if(begin==s.size()-1) return;
	int i;
	int iMax = begin;
	char vMax = s[iMax];
	for(i=begin+1;(i<s.size())&&(i<=begin+k);i++)
	{
		if(s[i]>vMax)
		{
			iMax = i;
			vMax = s[i];
		}
	}
	for(i=iMax;i>begin;i--)
		swap(s,i-1,i);
	gbest(s,begin+1,k-(iMax-begin));
}
int main()
{
	string s;
	int k;
	int i;
	cin >> s >> k;
	gbest(s,0,k);
	cout << s << endl;
}