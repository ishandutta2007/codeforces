#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;

string s, t, q, r;
int n;
vector <int> res;
void op (int a)
{
	res.pb(a);
	string alfa, beta;
	rep(i,0,n-a) alfa.pb(s[i]);
	rep(i,n-a,n) beta.pb(s[i]);
	s.clear();
	rep(i,0,a)
	{
		s.pb(beta.back());
		beta.pop_back();
	}
	s = s + alfa;
}

int main ()
{
	cin >>n >>s >>t;
	q = s;
	r = t;
	sort(q.begin(), q.end());
	sort(r.begin(), r.end());
	
	rep(i,0,n) if (q[i]!=r[i]) 
	{
		cout<<"-1\n";
		return 0;
	}
	
	int p;
	rep(pref,0,n) 
	{
		rep(i,0,n) if (s[i]==t[pref]) 
		{
			p = i;
			break;
		}
		
		
		op(n -p-1);
		//cerr<<s <<"\n";
		
		op(1);
		//cerr<<s <<"\n";
		
		op(n);
		//cerr<<s <<"\n";
	}
	printf ("%d\n", (int)res.size());
	for (int f: res) printf ("%d ", f);
	printf ("\n");
	
	//cerr <<s;
}