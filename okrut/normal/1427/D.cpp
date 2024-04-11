#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
bool sorted (vector <int> &tab)
{
	rep(i,0,n) if (tab[i]!=i+1) return false;
	return true;
}

void perform (vector <int> &tab, vector <int> op)
{
	vector <vector <int> > bits;
	
	reverse(tab.begin(), tab.end());
	//reverse(op.begin(), op.end());
	
	for (int o: op)
	{
		vector <int> rob;
		rep(i,0,o) 
		{
			rob.pb(tab.back());
			tab.pop_back();
		}
		bits.pb(rob);
	}
	
	reverse(bits.begin(), bits.end());
	
	for (auto wek: bits)
	{
		//reverse(wek.begin(), wek.end());
		for (auto x: wek) tab.pb(x);
	}
}


int main ()
{
	scanf ("%d", &n);
	
	vector <vector <int> > ops;
	
	vector <int> C(n);
	for (int &c: C) scanf ("%d", &c);
	
	while (!sorted(C))
	{
		debug ("Current state: ");
		for (int x: C) debug ("%d ", x);
		debug ("\n");
		
		int i=0;
		while (C[i]!=1) i++;
		int j=i+1;
		while (j<n and C[j]==C[j-1]+1) j++;
		
		set <int> cuts; //cut before this position
		cuts.insert(0);
		cuts.insert(n);
		cuts.insert(i);
		cuts.insert(j);
		
		debug ("Found [%d %d)\n", i, j);
		
		int len = j-i;
		if (i>0 and C[i-1]==len+1)
		{
			cuts.insert(i-1);
			len++;
		}
		
		debug ("The len is %d\n", len);
		
		if (len<n)
		{
			int k=0;
			while (k<n and C[k]!=len+1) k++;
			
			if (k<i)
			{
				cuts.insert(k);
			}
			else cuts.insert(k+1);
		}
		
		
		auto r = cuts.begin();
		auto l = cuts.begin();
		r++;
		
		vector <int> op;
		while (r!=cuts.end())
		{
			op.pb(*r - *l);
			r++;
			l++;
		}
		
		
		debug ("Operation: ");
		for (int x: op) debug ("%d ", x);
		debug ("\n");
		
		perform(C, op);
		
		ops.pb(op);
		
		assert( (int)ops.size() <=n);
	}
	
	printf ("%d\n", (int)ops.size());
	for (auto op: ops)
	{
		printf ("%d", (int)op.size());
		for (auto x: op) printf (" %d", x);
		printf ("\n");
	}
	
	
}