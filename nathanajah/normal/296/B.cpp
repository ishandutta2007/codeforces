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
int n;
string s1,s2;
int i;
int main()
{
	scanf("%d",&n);
	s1 = GetString();
	s2 = GetString();
	bool canless = true;
	bool canmore = true;
	LL MOD = 1000000007;
	LL res1 = 1;
	LL res2 = 1;
	LL reseq = 1;
	for (i=0;i<n;++i) {
		if (s1[i] == '?' && s2[i] == '?') {
			res1*=55;
			res2*=55;
			res1%=MOD;
			res2%=MOD;
			reseq = (10*reseq)%MOD;
		}
		else if (s1[i] == '?') {
			res1*=(s2[i]-'0')  + 1;
			res2*=('9'-s2[i]) + 1;
			res1%=MOD;
			res2%=MOD;
		}
		else if (s2[i] == '?') {
			res2*=(s1[i]-'0')  + 1;
			res1*=('9'-s1[i]) + 1;
			res1%=MOD;
			res2%=MOD;
		}
		else {
			if (s1[i] < s2[i])
				canmore = false;
			else if (s1[i] > s2[i])
				canless = false;
			if (s1[i] != s2[i])
				reseq = 0;
		}
	}
	LL res = 0;
	if (canless)
		res += res1;
	if (canmore)
		res += res2;
	res = (res + MOD - reseq) % MOD;
	res%=MOD;
	LL tenpow = 1;
	for (i=0;i<n;++i) {
		if (s1[i]=='?') {
			tenpow = (tenpow * 10)%MOD;
		}
		if (s2[i] == '?') {
			tenpow = (tenpow * 10)%MOD;
		}
	}
	printf("%I64d\n",(MOD + tenpow - res)%MOD);
}