#include <iostream>
#include <string>
using namespace std;

int eq,neq;
int vec[100000];

string s1,s2;
char s[100001];

char getun(char a,char b)
{
	char c = 'a';
	while(a == c || b == c)
		c++;
	return c;
}

int main()
{
	int N,T;
	cin >> N >> T;
	cin >> s1 >> s2;
	eq = neq = 0;
	for(int i=0;i<N;i++)
	{
		if(s1[i] == s2[i]) eq++;
		else neq++;
	}
	for(int i=0;i+1<neq;i+=2)
	{
		vec[i] = 1;
		vec[i+1] = 2;
		T--;
	}
	if(T > 0 && (neq&1))
		vec[neq-1] = 3, T--;
	else if(neq&1)
	{
		cout << -1 << '\n';
		return 0;
	}
	for(int i=0;i+1<neq;i+=2)
		if(T > 0)
		{
			vec[i] = vec[i+1] = 3;
			T--;
		}
	for(int i=0;i<eq;i++)
		if(T > 0)
		{
			vec[i+neq] = 3;
			T--;
		}
	if(T != 0)
	{
		cout << -1 << '\n';
		return 0;
	}
	int j = 0;
	for(int i=0;i<N;i++)
	{
		if(s1[i] != s2[i])
		{
			if(vec[j] == 1) s[i] = s1[i];
			if(vec[j] == 2) s[i] = s2[i];
			if(vec[j] == 3) s[i] = getun(s1[i],s2[i]);
			j++;
		}
	}
	for(int i=0;i<N;i++)
	{
		if(s1[i] == s2[i])
		{
			if(vec[j] == 0) s[i] = s1[i];
			if(vec[j] == 3) s[i] = getun(s1[i],s2[i]);
			j++;
		}
	}
	s[N] = '\0';
	cout << s << '\n';
}