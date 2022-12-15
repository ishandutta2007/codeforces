#include<bits/stdc++.h>
using namespace std;

char s[75]={'W','h','a','t',' ','a','r','e',' ','y','o','u',' ','d','o','i','n','g',' ','a','t',' ','t','h','e',' ','e','n','d',' ','o','f',' ','t','h','e',' ','w','o','r','l','d','?',' ','A','r','e',' ','y','o','u',' ','b','u','s','y','?',' ','W','i','l','l',' ','y','o','u',' ','s','a','v','e',' ','u','s','?'};
char str[34]={'W','h','a','t',' ','a','r','e',' ','y','o','u',' ','d','o','i','n','g',' ','w','h','i','l','e',' ','s','e','n','d','i','n','g',' ','"'};
char str2[32]={'"','?',' ','A','r','e',' ','y','o','u',' ','b','u','s','y','?',' ','W','i','l','l',' ','y','o','u',' ','s','e','n','d',' ','"'};
int n,q,lim;
long long k,len[100001]; 

char solve(int n,long long k)
{
	if (n<=lim&&len[n]<k) return '.';
	if (n==0) return s[k-1];
	if (k<=34) return str[k-1];
	if (n>lim||len[n-1]+34>=k) return solve(n-1,k-34);
	k-=(len[n-1]+34);
	if (k<=32) return str2[k-1];
	if (n>lim||len[n-1]+32>=k) return solve(n-1,k-32);
	k-=(len[n-1]+32);
	if (k==1) return '"';
	return '?';
}

int main()
{
	len[0]=75,lim=53;
	for (int i=1; len[i-1]<=1000000000000000000ll; i++) len[i]=2ll*len[i-1]+68;
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d%I64d",&n,&k);
		putchar(solve(n,k));
	}
	return 0;
}