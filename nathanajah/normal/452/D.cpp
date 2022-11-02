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
int wait[4];
int n[4];
int t[4];

priority_queue <pair<int,int> > x;

int main()
{
  scanf("%d %d %d %d %d %d %d", &wait[0], &n[0], &n[1], &n[2], &t[0], &t[1], &t[2]);
  int first = min(wait[0], n[0]);
  wait[0]-= first;
  n[0] -= first;
  for (int i=0;i<first;i++)
    x.push(make_pair(-t[0], 1));
  int tmax = t[0];
  while (!x.empty()) {
    pair <int,int> haha = x.top();
    tmax = max(tmax, -haha.fi);
    x.pop();
    haha.fi = -haha.fi;
    //get it out
    ++n[haha.se-1];
    //put waiting stuffs
    int tambah = min(n[haha.se-1], wait[haha.se-1]);
    n[haha.se-1] -= tambah;
    wait[haha.se-1] -= tambah;
    for (int i = 0; i < tambah; i++)
      x.push(make_pair(-(haha.fi + t[haha.se-1]), haha.se));
    //put it in
    if (haha.se == 3)
      continue;
    ++wait[haha.se];
    tambah = min(n[haha.se], wait[haha.se]);
    n[haha.se] -= tambah;
    wait[haha.se] -= tambah;
    for (int i = 0; i < tambah; i++)
      x.push(make_pair(-(haha.fi + t[haha.se]), haha.se+1));
  }
  printf("%d\n", tmax);
}