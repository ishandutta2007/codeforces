#include<iostream>
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int N=1e5+1e3+7,base=1313131,P=1e9+7;

typedef long long ll;

int n,m;

ll hash[N],mi[N],hs,f[N],sum[N],last[N];

char s[N],t[N];

ll gethash(ll l,ll r)
{
	return (hash[r]-hash[l-1]*mi[r-l+1]%P+P)%P;
}

int main()
{
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	mi[0]=1;
	for(int i=1;i<=n;i++)
		mi[i]=mi[i-1]*base%P;
	for(int i=1;i<=n;i++)
		hash[i]=((hash[i-1]*base)%P+s[i])%P;
	for(int i=1;i<=m;i++)
		hs=((hs*base)%P+t[i])%P;
	for(int i=m;i<=n;i++)
		if(gethash(i-m+1,i)==hs)
			last[i]=i-m+1;
		else
			last[i]=last[i-1];
	for(int i=1;i<=n;i++)  
    {  
        f[i]=f[i-1];  
        if(last[i]>0)  
          	f[i]=(f[i]+sum[last[i]-1]+last[i])%P;;
        sum[i]=(sum[i-1]+f[i])%P;
    }  
    printf("%lld",f[n]);
}