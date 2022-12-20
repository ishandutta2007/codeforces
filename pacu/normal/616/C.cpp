#include <iostream>
using namespace std;

int N,M;
char A[1001][1001];

int cid[1000000],sz[1000000];


void init()
{
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cid[i*M+j] = i*M+j, sz[i*M+j] = (A[i][j]=='.');
}
int find(int i)
{
	if(cid[i]==i) return i;
	cid[i] = find(cid[i]);
	return cid[i];
}
void join(int i,int j)
{
	i = find(i), j = find(j);
	if(i==j) return;
	if(sz[i] > sz[j]) swap(i,j);
	cid[i] = j;
	sz[j] += sz[i];
}

bool seen[1000000];

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> M;
	for(int i=0;i<N;i++)
		cin >> A[i];
	init();
	for(int i=0;i<N-1;i++)
		for(int j=0;j<M;j++)
			if(A[i][j]=='.' && A[i+1][j]=='.')
				join(M*i+j,M*(i+1)+j);
	for(int i=0;i<N;i++)
		for(int j=0;j<M-1;j++)
			if(A[i][j]=='.' && A[i][j+1]=='.')
				join(M*i+j,M*i+j+1);
	int ans;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(A[i][j]=='.')
				cout << '.';
			else
			{
				ans=1;
				if(i>0 && !seen[find((i-1)*M+j)])
				{
					seen[find((i-1)*M+j)] = 1;
					ans += sz[find((i-1)*M+j)];
				}
				if(i<N-1 && !seen[find((i+1)*M+j)])
				{
					seen[find((i+1)*M+j)] = 1;
					ans += sz[find((i+1)*M+j)];
				}
				if(j>0 && !seen[find(i*M+j-1)])
				{
					seen[find(i*M+j-1)] = 1;
					ans += sz[find(i*M+j-1)];
				}
				if(j<M-1 && !seen[find(i*M+j+1)])
				{
					seen[find(i*M+j+1)] = 1;
					ans += sz[find(i*M+j+1)];
				}
				if(i>0) seen[find((i-1)*M+j)] = 0;
				if(i<N-1) seen[find((i+1)*M+j)] = 0;
				if(j>0) seen[find(i*M+j-1)] = 0;
				if(j<M-1) seen[find(i*M+j+1)] = 0;
				cout << ans%10;
			}
		}
		cout << '\n';
	}
}