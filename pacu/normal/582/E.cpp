#include <iostream>
using namespace std;
#define MOD 1000000007

int b[17][1<<16];

int N;

void getSubs(int *a,int *ans)
{
	for(int i=0;i<(1<<N);i++)
		b[N][i] = a[i];
	for(int j=N-1;j>=0;j--)
		for(int i=0;i<(1<<N);i++)
		{
			b[j][i] = b[j+1][i];
			if(i&(1<<j)) b[j][i] = (b[j][i]+b[j+1][i-(1<<j)])%MOD;
		}
	for(int i=0;i<(1<<N);i++)
		ans[i] = b[0][i];
}

void getSups(int *a,int *ans)
{
	for(int i=0;i<(1<<N);i++)
		b[N][i] = a[i];
	for(int j=N-1;j>=0;j--)
		for(int i=0;i<(1<<N);i++)
		{
			b[j][i] = b[j+1][i];
			if(!(i&(1<<j))) b[j][i] = (b[j][i]+b[j+1][i|(1<<j)])%MOD;
		}
	for(int i=0;i<(1<<N);i++)
		ans[i] = b[0][i];
}

void remSubs(int *a)
{
	for(int i=0;i<(1<<N);i++)
		b[N][i] = a[i];	
	for(int j=N-1;j>=0;j--)
		for(int i=0;i<(1<<N);i++)
		{
			b[j][i] = b[j+1][i];
			if(i&(1<<j)) b[j][i] = (MOD+b[j][i]-b[j+1][i-(1<<j)])%MOD;
		}
	for(int i=0;i<(1<<N);i++)
		a[i] = b[0][i];	
}

void remSups(int *a)
{
	for(int i=0;i<(1<<N);i++)
		b[N][i] = a[i];
	for(int j=N-1;j>=0;j--)
		for(int i=0;i<(1<<N);i++)
		{
			b[j][i] = b[j+1][i];
			if(!(i&(1<<j))) b[j][i] = (MOD+b[j][i]-b[j+1][i|(1<<j)])%MOD;
		}
	for(int i=0;i<(1<<N);i++)
		a[i] = b[0][i];		
}

string s;

int subor[1<<16], supand[1<<16];
int sub1[1<<16], sub2[1<<16], sup1[1<<16],sup2[1<<16];

int eA,eB,eC,eD,ea,eb,ec,ed,eE;

int* dfs(int k1,int k2)
{
//	cout << k1 << ' ' << k2 << '\n';
	if(k1==k2)
	{
		int *eq = new int[65537];
		for(int i=0;i<(1<<N);i++)
			eq[i] = 0;
		eq[65536] = 1;
		if(s[k1]=='A' || s[k1]=='?')
		{
			for(int i=0;i<(1<<N);i++)
				eq[i] += (i==eA);
		}
		if(s[k1]=='B' || s[k1]=='?')
		{
			for(int i=0;i<(1<<N);i++)
				eq[i] += (i==eB);
		}
		if(s[k1]=='C' || s[k1]=='?')
		{
			for(int i=0;i<(1<<N);i++)
				eq[i] += (i==eC);
		}
		if(s[k1]=='D' || s[k1]=='?')
		{
			for(int i=0;i<(1<<N);i++)
				eq[i] += (i==eD);
		}
		if(s[k1]=='a' || s[k1]=='?')
		{
			for(int i=0;i<(1<<N);i++)
				eq[i] += (i==ea);
		}
		if(s[k1]=='b' || s[k1]=='?')
		{
			for(int i=0;i<(1<<N);i++)
				eq[i] += (i==eb);
		}
		if(s[k1]=='c' || s[k1]=='?')
		{
			for(int i=0;i<(1<<N);i++)
				eq[i] += (i==ec);
		}
		if(s[k1]=='d' || s[k1]=='?')
		{
			for(int i=0;i<(1<<N);i++)
				eq[i] += (i==ed);
		}
		if(s[k1]=='?')
			eq[65536] = 8;
//		cout << eq[0] << ' ' << eq[1] << ' ' << eq[2] << ' ' << eq[3] << '\n';
		return eq;
	}
	int c = k1;
	int depth = 1;
	while(depth != 0)
	{
		c++;
		if(s[c]=='(') depth++;
		else if(s[c]==')') depth--;
	}
	c++;
	int *eq1 = dfs(k1+1,c-2);
	int *eq2 = dfs(c+2,k2-1);
	int guess1 = eq1[65536];
	int guess2 = eq2[65536];
	getSubs(eq1,sub1);
//	cout << "SUB1: " << sub1[0] << ' ' << sub1[1] << ' ' << sub1[2] << ' ' << sub1[3] << '\n';
	getSubs(eq2,sub2);
//	cout << "SUB1: " << sub2[0] << ' ' << sub2[1] << ' ' << sub2[2] << ' ' << sub2[3] << '\n';
	getSups(eq1,sup1);
	getSups(eq2,sup2);
	for(int i=0;i<(1<<N);i++)
	{
		subor[i] = (((long long)sub1[i])*sub2[i])%MOD;
		supand[i] = (((long long)sup1[i])*sup2[i])%MOD;
	}
	delete [] eq1;
	delete [] eq2;
//	cout << "SUPAND: " << supand[0] << ' ' << supand[1] << ' ' << supand[2] << ' ' << supand[3] << '\n';
	remSubs(subor);
	remSups(supand);
	int *eq = new int[65537];
	for(int i=0;i<(1<<N);i++)
		eq[i] = 0;
	if(s[c]!='&')
	{
		for(int i=0;i<(1<<N);i++)
			eq[i] = (eq[i]+subor[i])%MOD;
	}
	if(s[c]!='|')
	{
		for(int i=0;i<(1<<N);i++)
			eq[i] = (eq[i]+supand[i])%MOD;	
	}
	eq[65536] = (((long long)guess1)*guess2)%MOD;
	if(s[c]=='?') eq[65536] = (eq[65536]*2LL)%MOD;
//	cout << eq[0] << ' ' << eq[1] << ' ' << eq[2] << ' ' << eq[3] <<  '\n';
	return eq;
}

int main()
{
	cin >> s >> N;
	int ai,bi,ci,di,ei;
	for(int i=0;i<N;i++)
	{
		cin >> ai >> bi >> ci >> di >> ei;
		eA += ai<<i;
		eB += bi<<i;
		eC += ci<<i;
		eD += di<<i;
		eE += ei<<i;
	}
	ea = eA ^ ((1<<N)-1);
	eb = eB ^ ((1<<N)-1);
	ec = eC ^ ((1<<N)-1);
	ed = eD ^ ((1<<N)-1);
//	cout << s.size() << '\n';
	int *final = dfs(0,s.size()-1);
	if(N==0)
		cout << final[65536] << '\n';
	else
		cout << final[eE] << '\n';
}