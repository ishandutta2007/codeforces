#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

string A[100001];
string B[100001];
int cA[100001];
int cB[100001];

bool cmpA(int a,int b)
{
	return A[a] < A[b];
}
bool cmpB(int a,int b)
{
	return B[a] < B[b];
}

int matA[100000];
int matB[100000];

int solve(int a1,int a2,int b1,int b2,int ch)
{
	if(a1>a2 || b1>b2) return 0;
//	cout << a1 << a2 << ' ' << b1 << b2 << ' ' << ch << '\n';
	int ta1 = a1;
	int tb1 = b1;
	while(a1 <= a2 && A[cA[a1]].size() == ch)
		a1++;
	while(b1 <= b2 && B[cB[b1]].size() == ch)
		b1++;
	int aa1,aa2,bb1,bb2;
	aa1 = a1;
	bb1 = b1;
	aa2 = a1-1;
	bb2 = b1-1;
	int ans = 0;
	for(char j='a';j<='z';j++)
	{
		if(aa1 > a2 || bb1 > b2)
			break;
		while(aa2 < a2 && A[cA[aa2+1]][ch] == j)
			aa2++;
		while(bb2 < b2 && B[cB[bb2+1]][ch] == j)
			bb2++;
		ans += min(aa2+1-aa1,bb2+1-bb1);
//		cout << min(aa2+1-aa1,bb2+1-bb1) << '\n';
		ans += solve(aa1,aa2,bb1,bb2,ch+1);
		aa1 = aa2+1;
		bb1 = bb2+1;
	}
	if(a2-ta1 <= b2-tb1)
	{
		int j = tb1;
		for(int i=ta1;i<=a2;i++)
		{
			if(matA[cA[i]] != -1) continue;
			while(matB[cB[j]] != -1)
				j++;
			matA[cA[i]] = cB[j];
			matB[cB[j]] = cA[i];
		}
	}
	else
	{
		int j = ta1;
		for(int i=tb1;i<=b2;i++)
		{
			if(matB[cB[i]] != -1) continue;
			while(matA[cA[j]] != -1)
				j++;
			matB[cB[i]] = cA[j];
			matA[cA[j]] = cB[i];
		}		
	}
//	cout << "OUT " << a1 << a2 << ' ' << b1 << b2 << ' ' << ch << '\n';
	return ans;
}

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		cA[i] = i;
	}
	for(int i=0;i<N;i++)
	{
		cin >> B[i];
		cB[i] = i;
	}
	sort(cA,cA+N,cmpA);
	sort(cB,cB+N,cmpB);
	A[N] = "";
	B[N] = "";
	for(int i=0;i<800000;i++) A[N] += ' ', B[N] += ' ';
	for(int i=0;i<N;i++)
		matA[i] = matB[i] = -1;
	cout << solve(0,N-1,0,N-1,0) << '\n';
	for(int i=0;i<N;i++)
		cout << i+1 << ' ' << matA[i]+1 << '\n';
}