#include <bits/stdc++.h>
using namespace std;
 #define MOD 1000000007
 #define A '@'
 #define B '*'
 #define C '#'
 #define max(a,b) ((a>b)?a:b)
 #define min(a,b) ((a<b)?a:b)
 #define endl "\n"
 struct frac {long x; long y;};
 frac operator+(frac a, frac b)
 {
 	frac res;
 	res.x=((a.x)*(b.y))%MOD+((b.x)*(a.y))%MOD;
 	res.x%=MOD;
 	res.y=a.y*b.y;
 	res.y%=MOD;
 	return res;
 }
 
 long long bow (long long a, long long x)
 {
 	if (!x) return 1;
	long long res=bow(a,x/2);
	res*=res; res%=MOD;
	if (x%2) res*=a;
	return (res)%MOD;
 }
 
 long long get_mod(long long x, long long y)
 {
 	long long d=__gcd(x,y);
 	x/=d;
 	y/=d;
 	x%=MOD;
 	y%=MOD;
 	return (x*(bow(y,MOD-2)))%MOD;
 }
 
 
 
typedef vector<int> vi;
 
// Union-Find Disjoint Sets Library
// PS: This library code does not include the `union by rank' heuristic yet
// 1000 is just a rough number, adjustable by user
vi pset(3000), setSize(3000); 
 
int _numDisjointSets;
 
void initSet(int N) { 
     setSize.assign(N, 1); 
     _numDisjointSets = N; 
     pset.assign(N, 0); 
     for (int i = 0; i < N; i++) pset[i] = i; 
}
 
int findSet(int i) { 
    return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); 
}
 
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
 
void unionSet(int i, int j) { 
  if (!isSameSet(i, j)) { 
    _numDisjointSets--; 
    setSize[findSet(j)] += setSize[findSet(i)]; 
    pset[findSet(i)] = findSet(j); } 
}
 
int numDisjointSets() { return _numDisjointSets; }
 
int sizeOfSet(int i) { return setSize[findSet(i)]; }
 
 
 
 
long long t,k,n,m, i,j,jj,mid,a,b,root;
vector <long long> cards;
long long p[2501],c[2501],res[2501];
vector <long long> child[2501];
vector<long long> ord[2501];
void dfs(int x)
{
	int a;
	for (int i=0; i<child[x].size();i++) 
	{
		a=child[x][i];
	dfs(a);
	for (int j=0;j<ord[a].size();j++) ord[x].push_back(ord[a][j]);
	}
	if (c[x]>ord[x].size()) {cout<<"NO"; exit(0);}
	ord[x].insert(ord[x].begin()+c[x],x);
}
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin>>n>>m>>k;
   initSet(n);
   for (i=0;i<=n-k;i++)
   for (j=0;j<k;j++) unionSet(j+i,k-1-j+i);
   cout<<bow(m,numDisjointSets());
}
/*
1880/1900
*/