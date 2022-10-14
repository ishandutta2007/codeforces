#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std; 
typedef long long ll;
typedef long double ld;

const int R = 1000;
const int C = 1000;
string tab[R];
int T[R*C], K[R*C], U[R*C]; //czas wierzcholka i jego poczatkowy kolor

priority_queue <pair <int, int> > kol;
void update (int x, int y, pair <int, int> p)
{
	int v = x*R+y;
	if (T[v]!=-1) return;
	
	K[v] = K[p.se];
	T[v] = -p.fi;
	kol.push({p.fi-1, v});
} 

int main ()
{
	ios_base::sync_with_stdio(false);
	int n, m, t;
	cin>>n >>m >>t;
	rep(i,0,n) cin>>tab[i];
	
	
	rep(x,0,n) rep(y,0,m)
	{
		bool nb = false;
		if (y>0 and tab[x][y-1]==tab[x][y]) nb = true;
		if (x>0 and tab[x-1][y]==tab[x][y]) nb = true;
		if (x+1<n and tab[x+1][y]==tab[x][y]) nb = true;
		if (y+1<m and tab[x][y+1]==tab[x][y]) nb = true;
		
		if (nb) 
		{
			kol.push({-1,x*R+y});
			K[x*R+y] = (tab[x][y]=='1' ? 1 : 0);
			T[x*R+y] = 0;
		}
		else T[x*R+y] = -1;
	}
	
	while (!kol.empty())
	{
		auto p = kol.top();
		kol.pop();
		if (U[p.se]>0) continue;
		U[p.se]++;
		int x = p.se/R;
		int y = p.se%R;
		
		int k = (K[p.se] ^ (-p.fi)) & 1; //czas mojego trwania w tej skladowej
		char c = (k==1 ? '1' : '0');
		
		if (y>0 and tab[x][y-1]==c) update(x,y-1,p);
		if (x>0 and tab[x-1][y]==c) update(x-1,y,p);
		if (x+1<n and tab[x+1][y]==c) update(x+1,y,p);
		if (y+1<m and tab[x][y+1]==c) update(x,y+1,p);
	}
	
	
	
	rep(q,0,t)
	{
		int x,y; 
		ll p;
		cin>>x >>y >>p;
		y--; x--;
		
		int v = x*R+y;
		
		if (p < T[v] or T[v]==-1)
		{
			cout<<tab[x][y]<<"\n";
			continue;
		}
		
		
		char ans = K[v]==1 ? '1' : '0';
		
		if (p %2 ==1) 
		{
			if (ans=='0') ans = '1';
			else ans = '0';
		}
		cout<<ans<<"\n";
	}
}