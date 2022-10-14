#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e3+5;

string S[N]; //obecne instrukcje
int typ[N]; //ile jest takiej instrukcji

int main ()
{
	int n;
	scanf ("%d", &n);
	vector <int> in(n);
	for (int &x: in) scanf ("%d", &x);
	
	//na poczatku sa zera
	int id = 0; //nowe
	for (int x: in)
	{
		id++;
		vector <int> ile(n+1, 0);
		int swp = -1;
		rep(i,0,n+1) if ((ile[typ[i]]++)==1) swp = typ[i];
		
		//musze zamienic id i
		bool fi = true;
		int jed = x, zer = n+1-x;
		
		rep(i,0,n+1) if (typ[i]==swp)
		{
			if (fi)
			{
				fi = false;
				S[i].pb('1');
				typ[i]=id;
				jed--;
			}
			else
			{
				if (zer>0)
				{
					S[i].pb('0');
					zer--;
				}
				else
				{
					S[i].pb('1');
					typ[i] = id;
					jed--;
				}
			}
		}
		rep(i,0,n+1) if (typ[i]<id && typ[i]!=swp)
		{
			if (jed>0) 
			{
				S[i].pb('1');
				jed--;
			}
			else
			{
				zer--;
				S[i].pb('0');
			}
		}
	}
	
	printf ("%d\n", n+1);
	rep(i,0,n+1) cout<<S[i]<<"\n";
}