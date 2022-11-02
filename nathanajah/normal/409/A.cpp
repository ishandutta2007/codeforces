//nathanajah's template
//28-11-2012
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <deque>
#include <map>
#include <ctime>
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned LL
#define INF 0x3FFFFFFF
#define INFLL 0x3FFFFFFFFFFFFFFF
#define SZ(a) (int)(a).size()
#define ALL(a) (a).begin(),(a).end()
#ifdef DEBUG
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
#else
	#define debug(...) 
#endif
using namespace std;

inline string GetString()
{
	char GS[1000005];
	scanf("%s",GS);string ret=GS;
	return ret;
}

inline char getc()
{
	char c=' ';
	while (c==' ' || c=='\t' || c=='\r' || c=='\n')
		c=getchar();
	return c;
}
//ENDOFTEMPLATE
string s1,s2;
int i;
int w1, w2;
int main()
{
	s1 = GetString();
	s2 = GetString();
	for (i=0;i<SZ(s1);i+=2) {
		if (s1[i] == '[' && s2[i] == '8')
			++w2;
		else if (s1[i]=='[' && s2[i] == '(')
			++w1;
		else if (s1[i]=='8' && s2[i]=='[')
			++w1;
		else if (s1[i]=='8' && s2[i]=='(')
			++w2;
		else if (s1[i]=='(' && s2[i]=='[')
			++w2;
		else if (s1[i]=='(' && s2[i]=='8')
			++w1;
	}
	if (w1>w2)
		printf("TEAM 1 WINS\n");
	else if (w1 < w2)
		printf("TEAM 2 WINS\n");
	else
		printf("TIE\n");
}