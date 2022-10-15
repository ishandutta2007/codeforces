#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
typedef vector<int> vi;
#define MOD 1000000007
vi pset(1000000), setSize(1000000); 
int n,m,i,j,k,p;
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

int bow(int a, int x)
{
	if (!x) return 1;
	int res=bow(a,x/2);
	res*=res;
	res%=MOD;
	if (x%2) res*=a;
	res%=MOD;
	return res;
}

signed main() {
	cin>>p>>k;
//	cout<<bow(2,3)<<endl;
	if (k==0)
	{
		cout<<bow(p,p-1); return 0;
	}
	if (k==1)
	{
		cout<<bow(p,p); return 0;
	}
	initSet(p);
	for (i=1;i<p;i++) unionSet(i,(i*k)%p);
	cout<<bow(p,numDisjointSets()-1);
}