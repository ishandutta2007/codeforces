#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+1;

char s[N][11];
int n,cnt[8];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(int i=1;i<=n;++i)
	for(int t=1;t<=7;++t)
	if(s[i][t]=='1')cnt[t]++;
	int ans=0;
	for(int i=1;i<=7;++i)if(cnt[i]>ans)ans=cnt[i];
	cout<<ans;
}