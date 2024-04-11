#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
using namespace std;

int cnt[100];
int cid[100];
int x[5000];

bool cmp(int a,int b)
{
	if(cnt[a]==cnt[b]) return a<b;
	return cnt[a]>cnt[b];
}

int main()
{
	int N,M;
	cin >> N >> M;
	for(int i=0;i<100;i++)
		cnt[i] = 0;
	int c;
	for(int i=0;i<N;i++)
	{
		cin >> x[i];
		x[i]--;
		cnt[x[i]]++;
	}
	sort(x,x+N,cmp);
	int good = N;
	if(cnt[x[0]] > (N-cnt[x[0]]))
		good -= 2*cnt[x[0]]-N;
	cout << good << endl;
	int j = 0;
	for(;j<N;j++)
		if(x[j] != x[0])
			break;
	if(j==N) j = 1;
	for(int i=0;i<N;i++,j++)
	{
		j = j%N;
		cout << x[i]+1 << " " << x[j]+1 << endl;
	}
}