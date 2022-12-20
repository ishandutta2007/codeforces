#include <iostream>
#include <algorithm>
using namespace std;

int N,M,K;
int A[100001];

int l[100000],r[100000],qid[100000];
long long qans[100000];

bool cmp(int a,int b)
{
	if(l[a]/317 == l[b]/317) return r[a]<r[b];
	else return l[a]<l[b];
}

int cnt[1<<20],cntk[1<<20];
long long ans;

void add(int v)
{
	cnt[v]++;
	ans += cntk[v];
	cntk[v^K]++;
	ans += cnt[v^K];
}
void remove(int v)
{
	cnt[v]--;
	ans -= cntk[v];
	cntk[v^K]--;
	ans -= cnt[v^K];
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> M >> K;
	int c;
	for(int i=1;i<=N;i++)
	{
		cin >> c;
		A[i] = A[i-1]^c;
	}
	for(int i=0;i<M;i++)
	{
		cin >> l[i] >> r[i];
		l[i]--;
		qid[i] = i;
	}
	sort(qid,qid+M,cmp);
	int cl = 0;
	int cr = 0;
	add(0);
	for(int i=0;i<M;i++)
	{
		while(cl > l[qid[i]])
		{
			cl--;
			add(A[cl]);
		}
		while(cr < r[qid[i]])
		{
			cr++;
			add(A[cr]);
		}
		while(cl < l[qid[i]])
		{
			remove(A[cl]);
			cl++;
		}
		while(cr > r[qid[i]])
		{
			remove(A[cr]);
			cr--;
		}
		qans[qid[i]] = ans;
		if(K==0) qans[qid[i]] -= (r[qid[i]]+1-l[qid[i]]);
		qans[qid[i]] /= 2;
	}
	for(int i=0;i<M;i++)
		cout << qans[i] << '\n';
}