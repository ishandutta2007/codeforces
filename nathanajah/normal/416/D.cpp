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
#define INF 0x3FFFFFFFFFFFFFFF
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
LL n,i;
LL arr[1000005];
vector <LL> conv;
int main()
{
	scanf("%I64d",&n);
	for (i=0;i<n;++i)
		scanf("%I64d",&arr[i]);
	LL cntneg = 0;
	LL negfront = 0;
	LL last = INF;
	LL res = 0;
	LL curdiff = INF;
	LL negmid = 0;
	for (i=0;i<n;++i) {
		if (arr[i] == -1) {
			if (curdiff == INF && last == INF) {
				negfront++;
			}
			else if (curdiff == INF) {
				negmid++;
			}
			else {
				if (last + curdiff <= 0){
					res++;
					last = INF;
					curdiff = INF;
					negfront = 1;
				}
				else
					last = last + curdiff;
			}
		}
		else {
			if (curdiff == INF && last == INF) {
				last = arr[i];
			}
			else if (curdiff == INF) {
				//find distance
				if ((arr[i] - last)%(negmid+1) == 0) {
					curdiff = (arr[i] - last)/ (negmid + 1);
					//check whether it's possible to fill the negfront
					if (arr[i] - curdiff * (negmid + 1 + negfront) <= 0) {
						++res;
						curdiff = INF;
					}
					negfront = 0;
					negmid = 0;
					last = arr[i];
				}
				else { //can't
					negfront = 0;
					negmid = 0;
					last = arr[i];
					++res;
				}
			} 
			else {
				if (last + curdiff != arr[i]) {
					last = arr[i];
					curdiff = INF;
					++res;
					negfront = 0;
					negmid = 0;
				}
				else
					last = arr[i];
			}
		}
	}
	if (negfront > 0 || negmid > 0 || last != INF || curdiff != INF)
		++res;
	printf("%I64d\n",res);
}