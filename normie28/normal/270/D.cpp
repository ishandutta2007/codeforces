#include <bits/stdc++.h>
using namespace std;
 #define MOD 1000000007
 #define A '@'
 #define B '*'
 #define C '#'
 #define max(a,b) ((a>b)?a:b)
 #define min(a,b) ((a<b)?a:b)
 #define endl "\n"
 struct frac {double x; long y;};
 
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

 
 
 
long long t,k,n,m, i,j,jj,mid,b,root;
vector <frac> pl;
double d;
long long dp[5001],a[5001],res[2501];
vector <long long> child[2501];
vector<long long> ord[2501];
int cmp (frac a, frac b)
{
	return (a.x<b.x);
}

int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin>>n>>m;
   for (i=1;i<=n;i++)
   {
   	cin>>b>>d;
   	pl.push_back({d,b});
   }
   sort (pl.begin(),pl.end(),cmp);
	for (i=1;i<=n;i++) a[i]=pl[i-1].y; b=0;
   for (i=1;i<=n;i++)
   {
   	dp[i]=0;
   	for (j=1;j<i;j++) if ((a[j]<=a[i])and(dp[j]>dp[i])) dp[i]=dp[j];
   	dp[i]++;
   	if (b<dp[i]) b= dp[i];
 //  	cout<<dp[i]<<' '<<a[i]<<endl;
   }
   cout<<n-b;
}
/*
1880/1900
*/