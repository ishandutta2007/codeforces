#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long uLL;
const int maxn=1000005;
char s[maxn];
bool cc[maxn],ans[maxn];
int n,k,calc[maxn];
int next[maxn],tmp[maxn];
void GetNext(char *T)
{
    int a=0;
    int Tlen=strlen(T);
    next[0]=Tlen;
    while(a<Tlen-1&&T[a]==T[a+1]) a++;
    next[1]=a;
    a=1;
    for(int k=2;k<Tlen;k++)
    {
        int p=a+next[a]-1,L=next[k-a];
        if((k-1)+L>=p)
        {
            int j=(p-k+1)>0? p-k+1:0;
            while(k+j<Tlen&&T[k+j]==T[j]) j++;
            next[k]=j;
            a=k;
        }
        else next[k]=L;
    }
}
void GetExtend(char *S,char *T)
{
    int a=0;
    GetNext(T);
    int Slen=strlen(S);
    int Tlen=strlen(T);
    int MinLen=Slen<Tlen? Slen:Tlen;
    while(a<MinLen&&S[a]==T[a]) a++;
    calc[0]=a;
    a=0;
    for(int k=1;k<Slen;k++)
    {
        int p=a+calc[a]-1,L=next[k-a];
        if((k-1)+L>=p)
        {
            int j=(p-k+1)>0? p-k+1:0;
            while(k+j<Slen&&j<Tlen&&S[k+j]==T[j]) j++;
            calc[k]=j;
            a=k;
        }
        else calc[k]=L;
    }
    for(int i=n;i>=1;i--)calc[i]=calc[i-1]+i-1;
}
int main()
{
	scanf("%d%d",&n,&k);
	if(k==1)
	{
		for(int i=1;i<=n;i++)putchar('1');
		return 0;
	}
	scanf("%s",s+1);
	GetExtend(s+1,s+1);
	for(int i=1;i<=n/k;i++)
		for(int j=1;j<=n/i;j++)
		{
			if(calc[(j-1)*i+1]<i*j)break;
			if(j%k==0)
			{
				tmp[i*j]=max(tmp[i*j],i*j);
				tmp[i*j]=max(tmp[i*j],min(i*j+i,calc[i*j+1]));
			}
		}
	int tt=0;
	for(int i=1;i<=n;++i)
	{
		tt=max(tt,tmp[i]);
		if(tt<i)putchar('0');
		else putchar('1');
	}
	return 0;
}