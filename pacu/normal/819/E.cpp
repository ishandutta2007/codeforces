#include <iostream>
using namespace std;

int ans[1000000][4];
int len[1000000];
int C;
int cnt[301][301];

void add3(int a,int b,int c)
{
	cnt[a][b]++,cnt[b][a]++,cnt[a][c]++,cnt[c][a]++,cnt[b][c]++,cnt[c][b]++;
	ans[C][0] = a;
	ans[C][1] = b;
	ans[C][2] = c;
	len[C] = 3;
	C++;
}

void add4(int a,int b,int c,int d)
{
	cnt[a][b]++,cnt[b][a]++,cnt[a][d]++,cnt[d][a]++,cnt[b][c]++,cnt[c][b]++,cnt[c][d]++,cnt[d][c]++;
	ans[C][0] = a;
	ans[C][1] = b;
	ans[C][2] = c;
	ans[C][3] = d;
	len[C] = 4;
	C++;
}

void solve(int l,int r)
{
	if(r+1-l==3)
	{
		add3(l,l+1,l+2);
		add3(l,l+1,l+2);
		return;
	}
	if(r+1-l==4)
	{
		add4(l,l+1,l+2,l+3);
		add4(l,l+2,l+1,l+3);
		add4(l,l+1,l+3,l+2);
		return;
	}
	solve(l+2,r);
	if((r+1-l)%2)
	{
		add3(l,l+1,l+2);
		add3(l,l+1,l+2);
		for(int i=l+3;i<r;i++)
		{
			add4(l,i,l+1,i+1);
		}
		add4(l,r,l+1,l+3);
	}
	else
	{
		add3(l,l+1,l+2);
		add3(l,l+1,l+3);
		add4(l,l+2,l+1,l+3);
		for(int i=l+4;i<r;i++)
		{
			add4(l,i,l+1,i+1);
		}
		if(l+4<r)
		{
			add4(l,r,l+1,l+4);
		}
	}
}

int main()
{
	int N;
	cin >> N;
	solve(1,N);
	if(C==-1)
	{
		cout << -1 << '\n';
		return 0;
	}
	cout << C << '\n';
	for(int i=0;i<C;i++)
	{
		cout << len[i] << ' ';
		for(int j=0;j<len[i];j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
	for(int i=1;i<=N;i++)
		for(int j=i+1;j<=N;j++)
			if(cnt[i][j]!=2)
				cout << "BAD " << i << ' ' << j << '\n';
}