#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <iostream>
#include <set>
#define ll long long
using namespace std;

char s[100500];
long long h[100500];
long long p[100500];
int n;

long long hash(int l,int r)
{
	if (l==0) return h[r] * p[n-1];
	return ( h[r]-h[l-1]) * p[n-l-1];
};

struct str
{
	int l,r;
	str(int a,int b) { l = a; r = b;}
	friend bool operator <(const str &a,const str &b)
	{
		if (s[a.l]!=s[b.l]) return s[a.l]<s[b.l];
		int len = min(a.r-a.l+1,b.r-b.l+1);
		int lm = 0; int rm = len;
		while (lm<rm)
		{
			int m = (lm+rm)>>1;
			if ( hash(a.l,a.l+m-1)!=hash(b.l,b.l+m-1) ) rm = m; else lm = m+1; 
		}
		if ( hash(a.l,a.l+len-1)==hash(b.l,b.l+len-1) )
		{
			return (a.r-a.l)<=(b.r-b.l);
		};
		
        if (s[a.l+lm-1]<s[b.l+lm-1]) return true; 
		 else if (s[a.l+lm-1]==s[b.l+lm-1]) return a.l<b.l; else return false;		
	}
};

set < str > myset; set < str >::iterator it;
void add(int l, int r)
{
	str _s(l,r);
	myset.insert(_s);
};


int main() {
    gets(s); int k; cin >> k; n = (int)strlen(s);
	if ((long long)k>(long long)n*(n+1)>>1) { puts("No such line.");return 0; }
	
	p[0] = 1ll; h[0] = s[0]-'a'+1;
	for (int i=1; i<n; i++)
		{ p[i] = p[i-1]*29ll; h[i] = h[i-1] + (s[i]-'a'+1)*p[i];}

	for (int i=0; i<n; i++) add(i,i);
	
 
	for (int i=1;i<k;i++)
	{
		 it = myset.begin();
		 myset.erase(it);
		 if (it->r<n-1) add(it->l,(it->r)+1);
	}
	
	it = myset.begin(); if (it->r<n-1) add(it->l,(it->r)+1); it = myset.begin();
	for (int i=it->l; i<=it->r; i++)
		putchar(s[i]);
	
    return 0;
}