#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cassert>
#include<cstring>
#include<vector>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<map>
 
using namespace std;
 
#define sz(c) (int)(c).size()
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
 
#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
 
#ifdef WIN32
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif
 
#define FNAME "1"

int n, k, d_win[100005], d_lose[100005], last_v, len, v;
char s[100005];

struct node
{
	int next[26];
};

node t[100005];

void dfs (int v)
{
	for (int i = 0; i < 26; i++)
		if (t[v].next[i] != 0)
			dfs(t[v].next[i]);
	
	int boo = 0;
	for (int i = 0; i < 26; i++)
		if (t[v].next[i] != 0 && d_win[t[v].next[i]] == 0)
			boo = 1;
	d_win[v] = boo;
	boo = 0;
	for (int i = 0; i < 26; i++)
		if (t[v].next[i] != 0 && d_lose[t[v].next[i]] == 0)
			boo = 1;
	d_lose[v] = boo;
	boo = 0;
	for (int i = 0; i < 26; i++)
		if (t[v].next[i] != 0)
			boo = 1;
	if (!boo)
		d_lose[v] = 1;
}

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d%d", &n, &k);
	last_v = 2;
	for (int i = 0; i < 26; i++)
		t[1].next[i] = 0;
	for (int i = 0; i < n; i++)
	{
		gets(s);
		v = 1;
		len = strlen(s);
		for (int i = 0; i < len; i++)
		{
			if (t[v].next[s[i] - 'a'] == 0)
			{
				for (int j = 0; j < 26; j++)
					t[last_v].next[j] = 0;
				t[v].next[s[i] - 'a'] = last_v++;
	        }
	      	v = t[v].next[s[i] - 'a'];
		}		
	}
	dfs(1);
	if (d_win[1] == 0)
		puts("Second");
	else
	{
		if (d_lose[1] == 1)
			puts("First");
		else
		{
			if (k % 2 == 1)
				puts("First");
			else
				puts("Second");
		}
	}
    return 0;
}