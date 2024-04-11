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

//Manacher's algorithm
void manacher (string &s, vector <int> &r) {
	int n = (int)s.size();
	r.clear(); r.resize(n, 1);
	int p = 0;
	while (p<n) {
		while (r[p]<=p && r[p]+p<n && s[p-r[p]]==s[p+r[p]]) r[p]++;
		if (r[p]==1) p++;
		else rep(d,1,r[p])
		{
			r[p+d] = min(r[p-d], r[p]-d);
			if (r[p+d]==r[p]-d) {
				p+=d;
				break;
			}
		}
	}
	rep(i,0,n) r[i]--;
}


string ans (string s)
{
	string parz, ans1;
	int n = s.size();
	
	//cerr <<"do for : " <<s <<"\n";
	
			parz.pb('#');
			for (char c: s)
			{
				parz.pb(c);
				parz.pb('#');
			}
			
			vector <int> p, np;
			manacher(s, np);
			manacher(parz, p);
			
			int len = 0;
			while (len < n && s[len] == s[n-len-1]) len++;
			
			int res = 0;
			int pref = 0;
			
			rep(pos,0,n)
			{
				//parzyste
				int rn = np[pos];
				int rp = p[pos*2]/2;
				
				debug ("at %d: %d %d\n", pos, rp, rn);
				
				if (pos*2 <= n && pos - rp <= len)
				{
					debug ("way = %d\n", pos*2);
					
					if (res < pos *2)
					{
						res = pos*2;
						pref = pos + rp;
					}
				}
				
				if (pos*2 +1 <= n && pos - rn <= len)
				{
					debug ("way = %d\n", pos*2+1);
					
					if (res < pos *2 +1)
					{
						res = pos *2 +1;
						pref = pos + rn +1;
					}
				}
			}
			
			rep(i,0,pref) ans1.pb(s[i]);
			int suf = res - pref;
			rep(i,n-suf,n) ans1.pb(s[i]);
			
	return ans1;
}
int main ()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while (t--)
	{
		string s;
		cin>>s;
		
		string ans1 = ans(s);
		reverse(s.begin(), s.end());
		string ans2 = ans(s);
		
		if (ans1.size() < ans2.size()) 
		{
			cout<<ans2<<"\n";
		}
		else cout<<ans1<<"\n";
	}
}