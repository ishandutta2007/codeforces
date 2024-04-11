#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug // 
using namespace std;
typedef long long ll;
typedef long double ld;



int main ()
{
	//ios_base::sync_with_stdio(false);
	string s;
	cin>>s;
	int n = s.size();
	int res= 0;
	rep(a,0,n)
	{
		int l = 0, r = 0, q = 0, open = 0;
		int len = 0, stan = 0;
		int stuck = a, rect = a;
		rep(b,a,n)
		{
			if (s[b]=='(') 
			{
				open--;
				l++;
			}
			if (s[b]==')') 
			{
				open++;
				r++;
			}
			if (s[b]=='?') 
			{
				open++;
				q++;
			}
			len++;
			
			
			while (stuck<=b)
			{
				while (rect<stuck)
				{
					if (s[rect]=='?')
					{
						if (open>=2)
						{
							stan+=2;
							open-=2;
						}
						else break;
					}
					rect++;
				}
				
				if (stan<0) break;
				
				while (stuck<=b && stan>=0)
				{
					if (s[stuck]=='(') stan++;
					if (s[stuck]==')') stan--;
					if (s[stuck]=='?') 
					{
						stan--;
					}
					stuck++;
				}
				
			}
			
			debug ("check [%d %d] %d %d with %d (open %d)\n", a, b, stuck, rect, stan, open);
			
			if (stan==0 && stuck==b+1) 
			{
				debug ("plus\n");
				res++;
			}
		}
	}
	cout<<res <<"\n";
}