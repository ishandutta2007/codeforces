#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+1;
char s[51],s1[51];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	int tag=0;
	if(n==1){cout<<"YES";return 0;}
	for(int i=1;i<=n/2;++i)tag+=(s[i]!=s[n+1-i]);
	if(n&1)cout<<(tag<=1?"YES":"NO");
	else	cout<<(tag==1?"YES":"NO");
}