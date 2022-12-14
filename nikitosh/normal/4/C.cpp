#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

int n;
string s;
map <string, int> m;

int main()
{
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{            
		cin >> s;
		if (m[s] == 0)
		{
			printf("OK\n");
			m[s]++;
		}
		else
		{
			cout << s << m[s] << endl;
			m[s]++;
		}
	}
	return 0;
}