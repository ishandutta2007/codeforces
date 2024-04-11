#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,mx,id,a[2200005],ct,b[2200005],c[2200005],st;
char s[2200005],s2[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s2+1);
		n=strlen(s2+1);
		for(int i=0;i<=n;i++)
			b[i]=0,c[i]=1e9;
		int l=0,r=n+1;
		while(l<r-2&&s2[l+1]==s2[r-1])
			l++,r--;
		st=0;
		ct=0;
		s[++st]='!';
		for(int i=1;i<=n;i++)
		{
			s[++st]='#';
			s[++st]=s2[i];
		}
		s[++st]='#';
		//printf("%s\n",s);
		s[++st]='@';
		s[st+1]=0;
		mx=id=0;
		for(int i=2;i<=st;i++)
		{
			if(mx<i) a[i]=0;
			else a[i]=min(a[2*id-i],mx-i);
			while(s[i-a[i]-1]==s[i+a[i]+1]) a[i]++;
			if(i+a[i]>mx)
			{
				mx=i+a[i];
				id=i;
			}
			int tl=(i-a[i])/2,tr=(i+a[i])/2-1;
			if(tl<=n-tr+1)
				b[tl]=max(b[tl],tr);
			if(tl>=n-tr+1) c[tr]=min(c[tr],tl);
		//	printf("i=%d,a=%d,tl=%d,tr=%d\n",i,a[i],tl,tr);
		}
		for(int i=2;i<=n;i++)
			b[i]=max(b[i],b[i-1]-1);
		for(int i=n-1;i>0;i--)
			c[i]=min(c[i],c[i+1]+1);
		int ans=0,id1=0,id2=0;
		for(int i=0;i<=l;i++)
		{
			int j=n+1-i;
			int llen=max(b[i+1]-i,0),rlen=max(j-c[j-1],0);
			int val=2*i+max(llen,rlen);
			if(ans<val)
			{
				ans=val;
				id1=i;
				id2=(max(llen,rlen)==rlen);
			}
		}
		for(int i=1;i<=id1;i++)
			printf("%c",s2[i]);
		int mid=ans-2*id1;
		if(id2==0)
		{
			for(int i=id1+1;i<=id1+mid;i++)
				printf("%c",s2[i]);
		}
		else
		{
			
			for(int i=(n-id1)-mid+1;i<=(n-id1);i++)
				printf("%c",s2[i]);
		}
		for(int i=n-id1+1;i<=n;i++)
			printf("%c",s2[i]);
		printf("\n");
	}
	return 0;
	return 0;
}