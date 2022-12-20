#include <iostream>
using namespace std;

int dist1[100000],dist2[100000];
int A[100000];
int N,Q;

int que[100000];
int qval[100000];

int q1[100],q2[100];

int aa(int a)
{
	if(a<0) return -a;
	return a;
}

int main()
{
	cin >> N >> Q;
	for(int i=0;i<N;i++)
		cin >> A[i];
	int a,b;
	for(int i=0;i<Q;i++)
	{
		cin >> a >> b;
		a--,b--;
		long long ans = 0;
		int sz = 1;
		que[0] = a+1;
		qval[0] = aa(A[a+1]-A[a]);
		dist1[a+1] = a;
		for(int j=a+2;j<=b;j++)
		{
			while(sz>0 && qval[sz-1]<aa(A[j]-A[j-1]))
				sz--;
			if(sz>0)
				dist1[j] = que[sz-1];
			else
				dist1[j] = a;
			que[sz] = j;
			qval[sz] = aa(A[j]-A[j-1]);
			sz++;
		}
		sz = 1;
		que[0] = b;
		qval[0] = aa(A[b]-A[b-1]);
		dist2[b] = b;
		for(int j=b-1;j>a;j--)
		{
			while(sz>0 && qval[sz-1]<=aa(A[j]-A[j-1]))
				sz--;
			if(sz>0)
			{
				dist2[j] = que[sz-1]-1;
			}
			else
				dist2[j] = b;
			que[sz] = j;
			qval[sz] = aa(A[j]-A[j-1]);
			sz++;
		}
		for(int j=a+1;j<=b;j++)
		{
			ans += ((long long)(j-dist1[j]))*((long long)(dist2[j]+1-j))*((long long)aa(A[j]-A[j-1]));
//			cout << dist1[j] << ' ' << dist2[j] << '\n';
		}
		cout << ans << '\n';
	}
}