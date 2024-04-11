#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

deque <int> kol;
int inw;
int right()
{
	if (inw==0) return kol.back();
	else return 1^kol.front();
}

int left()
{
	if (inw==0) return kol.front();
	else return 1^kol.back();
}

void erase(int x)
{
	if ((x^inw)==0) kol.pop_back();
	else kol.pop_front();
}

void printSuffix()
{
	vector <int> suffix;
	for (int k: kol) suffix.pb(k);
	
	if (inw) reverse(suffix.begin(), suffix.end());
	debug ("Suffix: ");
	for (int x: suffix) debug ("%d ", x^inw);
	debug ("\n");
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	rep(q,0,t)
	{
		int n;
		inw = 0;
		string a, b;
		cin>>n >>a >>b;
		
		vector <int> ops;
		
		
		rep(i,0,n) kol.push_back(a[i] - '0');
		
		for (int i=n-1; i>=0; i--)
		{
			int c = b[i] - '0';
			if (c==right()) erase(0);
			else if (left()==right())
			{
				ops.pb(i+1);
				inw^=1;
				erase(0);
			}
			else 
			{
				ops.pb(1);
				erase(1);
				ops.pb(i+1);
				inw^=1;
			}
		}
		
		
		cout<<ops.size();
		for (int o: ops) cout<<" " <<o;
		cout<<"\n";
	}
	
}