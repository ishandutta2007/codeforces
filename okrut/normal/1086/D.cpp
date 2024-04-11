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
string sym;
int n, q;
struct baum
{
	vector <int> tree;
	void init ()
	{
		tree.resize(n*6+100,0);
	}
	void add (int x, int y, int a=1, int lewy=0, int prawy=n-1)
	{
		if (lewy<prawy)
		{
			if (x<=mitte) add(x,y, a*2,lewy, mitte);
			if (x>mitte) add(x,y, a*2+1, mitte+1, prawy);
			tree[a]=tree[a*2]+tree[a*2+1];
		}
		else tree[a]+=y;
	}
	int sum (int left, int right, int a=1, int lewy=0, int prawy=n-1)
	{
		if (right<left) return 0;
		//debug ("sum %d %d: %d %d %d - %d\n", left, right, a, lewy, prawy, tree[a]);
		if (left<=lewy && right>=prawy) return tree[a];
		else
		{
			int ret=0;
			if (left<=mitte) ret+=sum(left, right, a*2, lewy, mitte);
			if (right>mitte) ret+=sum(left, right, a*2+1, mitte+1, prawy);
			return ret;
		}
	}
};
baum tree[3];
set <int> wor[3];
int lewy (int a)
{
	auto it=wor[a].begin();
	if (it==wor[a].end()) return 1e9; //w owogle go nie ma
	return *it;
}
int prawy (int a)
{
	auto it=wor[a].end();
	if (it==wor[a].begin()) return -1;
	it--;
	return *it;
}
int policz (int ja, int zly, int dobry)
{
	int lz=lewy(zly), ld=lewy(dobry), pz=prawy(zly), pd=prawy(dobry);
	
	int ret=0;
	if (lz>n) //nie ma zlego - w ogole
	{
		return tree[ja].sum(0,n-1);
	}
	if (ld>n) return 0; //nie ma tez dobrego
	
	ret+=tree[ja].sum(0,min(lz,ld));
	ret+=tree[ja].sum(ld,pd);
	ret+=tree[ja].sum(max(pz,pd), n-1);
	debug ("licze %d (%d %d) - %d (%d) %d (%d) - %d\n", ja, zly, dobry, lz, ld, pz, pd, ret);
	return ret;
}
int main ()
{
	cin>>n >>q;
	rep(i,0,3) tree[i].init();
	cin>>sym;
	rep(i,0,n)
	{
		if (sym[i]=='R')
		{
			tree[0].add(i,1);
			wor[0].insert(i);
		}
		if (sym[i]=='P')
		{
			tree[1].add(i,1);
			wor[1].insert(i);
		}
		if (sym[i]=='S')
		{
			tree[2].add(i,1);
			wor[2].insert(i);
		}
	}
	int res;
	int a;
	char c;
	rep(i,0,q)
	{
		res=policz(0,1,2)+policz(1,2,0)+policz(2,0,1);
		cout<<res <<"\n";
		cin>>a >>c;
		a--;
		if (sym[a]=='R')
		{
			tree[0].add(a,-1);
			wor[0].erase(a);
		}
		if (sym[a]=='P')
		{
			tree[1].add(a,-1);
			wor[1].erase(a);
		}
		if (sym[a]=='S')
		{
			tree[2].add(a,-1);
			wor[2].erase(a);
		}
		sym[a]=c;
		if (sym[a]=='R')
		{
			tree[0].add(a,1);
			wor[0].insert(a);
		}
		if (sym[a]=='P')
		{
			tree[1].add(a,1);
			wor[1].insert(a);
		}
		if (sym[a]=='S')
		{
			tree[2].add(a,1);
			wor[2].insert(a);
		}
		//cerr<<sym <<"\n";
	}
	res=policz(0,1,2)+policz(1,2,0)+policz(2,0,1);
	cout<<res <<"\n";
}