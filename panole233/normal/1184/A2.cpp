#include<bits/stdc++.h>
using namespace std;

int n,ans;
char s[200010];
bool bo[200010];

int gcd(int a,int b) {return (!b)?a:gcd(b,a%b);}

int main()
{
	scanf("%d",&n);
	scanf("%s",s),bo[0]=1;
	for (int i=0; i<n; i++) if (s[i]!='0') {bo[0]=0; break;}
	if (bo[0]) return printf("%d\n",n),0;
	for (int i=1; i<n; i++)
		if (n%i==0)
		{
			bo[i]=1;
			for (int j=0; j<i; j++)
			{
				int nw=0;
				for (int k=j; k<n; k+=i) nw^=(s[k]-'0');
				if (nw) {bo[i]=0; break;}
			}
		}
	for (int i=1; i<n; i++) if (bo[gcd(i,n)]) ans++;
	printf("%d\n",ans);
	return 0;
}