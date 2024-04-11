#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int inf = 2000000000;
char s[510]; int K;
int cnt[510][510];
int d[510][510];
int p[510][510];
int n;

int main() {
	gets(s); scanf("%d",&K); n = (int)strlen(s);
	for (int i=0;i<n;i++)
		for (int j=i;j<n;j++)
		{
			cnt[i][j] = 0;
			for (int k=i;k<=(i+j)>>1;k++)
				if (s[k] != s[j-k+i]) cnt[i][j]++;
	    }
	
	for (int i=0; i<n; i++)
		for (int k=1; k<=i+1; k++)
		{
			d[i][k] = inf;
			if (k == 1) { d[i][k] = cnt[0][i]; continue;}
			for (int j=k-2; j<i; j++)
				if (d[j][k-1] + cnt[j+1][i] < d[i][k]) 
				{
					d[i][k] = d[j][k-1] + cnt[j+1][i]; p[i][k] = j; 
				}
		}
	
	int m = 1;
	for (int i=2; i<=K; i++)
		if (d[n-1][i] < d[n-1][m]) m = i;
	cout << d[n-1][m] << endl;
	vector < int > res;
	
	int j = n-1; 
	res.push_back(n-1);
	while (m > 1)
	{
		res.push_back(p[j][m]); j = p[j][m]; m--;
	}
	
	j = 0;
	for (int i=(int)res.size()-1; i>=0; i--)
	{
		for (int k=j;k<=(res[i]+j)>>1;k++)
			if (s[k]!=s[res[i]-k+j]) s[k]=s[res[i]-k+j];
		for (int k=j; k<=res[i]; k++)
			cout<<s[k];
		if (res[i]!=n-1) cout<<'+'; j = res[i]+1;
	}
	return 0;
}