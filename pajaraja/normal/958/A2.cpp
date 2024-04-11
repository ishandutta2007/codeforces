#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long st[40007];
char ta[2007][207],tb[207][2007];
long long hsha[2007],hshb[2007];
int main()
{
	st[0]=1;
	for(int i=1;i<40005;i++) st[i]=(30*st[i-1])%MOD;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>ta[i][j];
	for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin>>tb[i][j];
	for(int i=0;i<=n-m;i++) for(int j=0;j<m;j++) for(int k=0;k<m;k++) hsha[i]=(hsha[i]+st[j*m+k]*(ta[i+j][k]-'a'+1))%MOD;
	for(int i=0;i<=n-m;i++) for(int j=0;j<m;j++) for(int k=0;k<m;k++) hshb[i]=(hshb[i]+st[j*m+k]*(tb[j][i+k]-'a'+1))%MOD;
	for(int i=0;i<=n-m;i++) for(int j=0;j<=n-m;j++) if(hsha[i]==hshb[j]) {cout<<i+1<<" "<<j+1; return 0;}
}