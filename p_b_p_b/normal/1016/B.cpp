#include<bits/stdc++.h>
using namespace std;
char a1[2000],a2[2000];
int kmp[2000];
int n,m,q,l,r,ans;
int main()
{
    scanf("%d %d %d\n",&n,&m,&q);
    cin>>a1>>a2;
    kmp[0]=kmp[1]=0;
    int k;
    k=0;
    for(int i=1;i<m;i++)
    {
        while(k&&a2[i]!=a2[k]) k=kmp[k];
        kmp[i+1]=(a2[i]==a2[k]?++k:0);
    }
    while (q--)
    {
    	scanf("%d %d",&l,&r);
		k=ans=0;
    	for(int i=l-1;i<r;i++)
    	{
    	    while(k&&a1[i]!=a2[k]) k=kmp[k];
    	    k+=a1[i]==a2[k]?1:0;
    	    if(k==m) ++ans;
    	}
    	printf("%d\n",ans);
    }
}