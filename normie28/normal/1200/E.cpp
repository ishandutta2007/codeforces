#include<bits/stdc++.h>
#define sc scanf
#define pr printf
using namespace std;
const int maxn = 1e6 + 10;
void cal_next(char* str, int* nex, int len)
{
	nex[0] = nex[1] = 0;
	for (int i = 1; i < len; ++i)
	{
		int j = nex[i];
		while (j && str[i] != str[j])
			j = nex[j];
		nex[i + 1] = (str[j] == str[i]) ? j + 1 : 0;
	}
}
int nex[maxn];
int kmp(char* str, int slen, char* ptr, int plen)
{
	cal_next(ptr, nex, plen);
	int j = 0;
	for (int i = max(0, slen - plen); i < slen; i++)
	{
		while (j && ptr[j] != str[i])
			j = nex[j];
		if (ptr[j] == str[i])
			++j;
	}
	return j;
}
char str[maxn], ptr[maxn];
int main()
{
	int n;
	cin>>n>>str;
	int slen = strlen(str);
	for (int i = 1; i < n; i++)
	{
		cin>>ptr;
		int plen = strlen(ptr);
		int len = kmp(str, slen, ptr, plen);
		for (int i = len; i < plen; i++)
			str[slen++] = ptr[i];
	}
	str[slen] = '\0';
	cout<<str;
}