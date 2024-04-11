#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MOD 1000000007

int fact[300001];
int invfact[300001];


int pw(int a,int e)
{
	if(e==0) return 1;
	int tmp = pw(a,e/2);
	tmp = (tmp*((long long)tmp))%MOD;
	if(e&1) tmp = (tmp*((long long)a))%MOD;
	return tmp;
}

void computeFactorials()
{
	fact[0] = invfact[0] = 1;
	for(int i=1;i<=300000;i++)
	{
		fact[i] = (fact[i-1]*((long long)i))%MOD;
		invfact[i] = pw(fact[i],MOD-2);
	}
}

void mult(int &a,int b)
{
	a = (a*((long long)b))%MOD;
}
void add(int &a,int b)
{
	a = a+b;
	if(a>=MOD) a -= MOD;
}
void sub(int &a,int b)
{
	a = a+MOD-b;
	if(a>=MOD) a -= MOD;
}

int chs(int n,int k)
{
	if(k>n) return 0;
	int tmp = (fact[n]*((long long)invfact[k]))%MOD;
	tmp = (tmp*((long long)invfact[n-k]))%MOD;
	return tmp;
}

vector<int> pcs[300001];

int A[300000];
int occ[20];
int ps[20];
int N,C;

int tmp[300001];

int computePrime(int p)
{
	for(int i=0;i<20;i++)
		occ[i] = 0;
	for(int j=0;j<pcs[p].size();j++)
	{
		int l = 0;
		while(pcs[p][j]%p==0)
		{
			l++;
			pcs[p][j] /= p;
		}
		occ[l]++;
//		cout << p << ": " << pcs[p][j] << ": " << l << '\n';
	}
	occ[0] = N - pcs[p].size();
	int numLess = 0;
	int numMore;
	int ans = 0;
	for(int k=0;k<19;k++)
	{
		numLess += occ[k];
		numMore = N - numLess;
		//more of the Mores then of the Lesses
		tmp[0] = 0;
		for(int i=1;i<numMore;i++)
		{
			tmp[i] = i;
			mult(tmp[i],chs(numLess,i));
			add(tmp[i],tmp[i-1]);
			int cur = tmp[i];
			mult(cur,chs(numMore,i+1));
			add(ans,cur);
		}
		//at least as many of the Lesses as of the Mores
		tmp[0] = pw(2,numLess);
		for(int i=1;i<=numMore;i++)
		{
			tmp[i] = tmp[i-1];
			sub(tmp[i],chs(numLess,i-1));
			int cur = tmp[i];
			mult(cur,chs(numMore,i));
			mult(cur,i);
			add(ans,cur);
		}
		//cout << ans << '\n';
	}
	//cout << p << ": " << ans << '\n';
	return ans;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	computeFactorials();
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		int c = A[i];
		for(int j=2;j*j<=A[i];j++)
		{
			if(c%j==0)
			{
				pcs[j].push_back(A[i]);
				while(c%j==0)
					c /= j;
			}
		}
		if(c>1)
		{
			pcs[c].push_back(A[i]);
		}
	}
	int ans = 0;
	for(int i=1;i<=300000;i++)
		if(pcs[i].size()>0)
			add(ans,computePrime(i));
	cout << ans << '\n';
	//cout << computePrime(2) << '\n';
}