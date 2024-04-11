#include <iostream>
#include <string>
#include <vector>
using namespace std;

int isLetter(char c)
{
	return ((97<=c)&&(c<=122));
}
int isDigit(char c)
{
	return ((48<=c)&&(c<=57));
}
int isUnderscore(char c)
{
	return c==95;
}
long long aBefore[1000000];
long long aAfter[1000000];
string s;
int N;

int getDot(int i)
{
	int j = i+1;
	while(j<N)
	{
		if(s[j]=='.')
		{
			if(j==i+1)
				return -1;
			return j;
		}
		if(!(isLetter(s[j])||isDigit(s[j])))
			return -1;
		j++;
	}
	return -1;
}

int main()
{
	cin >> s;
	N = s.size();
	int i,j;
	int count;
	int next;
	for(i=0,count=0;i<N;i++)
	{
		if(s[i]=='@')
		{
			aBefore[i] = count;
			count = 0;
			continue;
		}
		if(isLetter(s[i]))
			count++;
		if(!(isLetter(s[i])||isDigit(s[i])||isUnderscore(s[i])))
			count = 0;
	}

	for(i=N-1,count=0;i>=0;i--)
	{
		if(s[i]=='.')
		{
			aAfter[i] = count;
			count = 0;
			continue;
		}
		if(isLetter(s[i]))
			count++;
		else
			count = 0;
	}
	long long ans = 0;
	for(i=0;i<N;i++)
	{
		if(s[i]!='@')
			continue;
		next = getDot(i);
		if(next==-1)
			continue;
		ans += aBefore[i]*aAfter[next];
	}
	cout << ans << endl;
}