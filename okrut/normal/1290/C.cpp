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

const int N = 3e5+10;

int ojce[N], Fixed[N], State[N], ComFlip[N], Want[N], Moc[N], On[N];
vector <int> graf[N];
pair <int, int> Edge[N];
int stan;

int krol (int a)
{
	if (ojce[a]==0) return a;
	return (ojce[a] = krol(ojce[a]));	
}

//zmien skladowa a
void flip (int a)
{
	stan -= On[a];
	On[a] = Moc[a] - On[a];
	stan += On[a];
	ComFlip[a] ^=1;
}

void writeVals(int a, int b, int ka)
{
	State[a]^=ComFlip[ka];
	for (int s: graf[a]) if (s!=b)
	{
		writeVals(s, a, ka);
	}
}

bool unia (int a, int b, int id)
{
	int ka = krol(a), kb = krol(b);
	
	if (ka==kb)
	{
		return false;
	}
	
	if (((State[a]^ComFlip[ka]) ^ (State[b] ^ ComFlip[kb])) != Want[id])
	{
		if (Fixed[ka] and Fixed[kb])
		{
			//smth went wrong
			//assert(0);
		}
			
		int who;
		if (Moc[ka] - 2*On[ka] <= Moc[kb] - 2*On[kb])
		{
			who = ka;
		}
		else who = kb;
		
		if (Fixed[ka]) who = kb;
		if (Fixed[kb]) who = ka;
		
		
		flip(who);
	}
	
	if (Moc[ka] < Moc[kb]) swap(ka, kb);
	
	if ( (ComFlip[ka]^ComFlip[kb]) ==1)
	{
		ComFlip[kb] = 1;
		writeVals(kb, kb, kb);
	}
	
	ojce[kb] = ka;
	
	graf[ka].pb(kb);
	graf[kb].pb(ka);
	
	On[ka] += On[kb];
	Moc[ka] += Moc[kb];
	Fixed[ka] |= Fixed[kb];
	
	return true;
}

int main ()
{
	ios_base::sync_with_stdio(false);
	int n, k;
	string s;
	cin>>n >>k >>s;
	rep(i,1,k+1)
	{
		int m;
		cin>>m;
		rep(v,0,m)
		{
			int a;
			cin>>a;
			a--;
			if (Edge[a].fi==0) Edge[a].fi = i;
			else Edge[a].se = i;
		}
	}
	rep(i,0,n) Want[i] = (s[i] - '0') ^ 1;
	
	stan = 0;
	rep(i,1,k+1)
	{
		Moc[i] = 1;
		
	}
	
	rep(i,0,n)
	{
		if (Edge[i].se>0)
		{
			unia(Edge[i].fi, Edge[i].se, i);
		}
		else if (Edge[i].fi >0)
		{
			int x = Edge[i].fi;
			int kx = krol(x);
			int curr = State[x] ^ ComFlip[kx];
			if (curr!=Want[i])
			{
				flip(kx);
			}
			Fixed[kx] = 1;
		}
		else
		{
			assert(Want[i]==0);
		}
		cout<<stan <<"\n";
	}
}