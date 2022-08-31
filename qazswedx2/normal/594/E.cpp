#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[5000005],sr[5000005],tmp[10000005],ans1[5000005],ans2[5000005];
char ans3[5000005];
int n,k,a[5000005],b[5000005],at,bt,d[5000005],t1,t2,t3,f[10000005];
void exkmp()
{
	for(int i=1;i<=n;i++)
		tmp[i]=sr[i];
	for(int i=1;i<=n;i++)
		tmp[i+n]=s[i];
	int l=0,r=0;
	for(int i=2;i<=2*n;i++)
	{
		if(r<i) f[i]=0;
		else f[i]=min(r-i+1,f[i-l+1]);
		while(i+f[i]<=2*n&&tmp[i+f[i]]==tmp[f[i]+1]) f[i]++;
		if(r<f[i]) l=i,r=f[i];
	}
	f[1]=2*n;
}
int query(int l,int r)
{
/*	printf("query:l=%d,r=%d\n",l,r);
	printf("s=");
	for(int i=l;i<=r;i++)
		printf("%c",tmp[i]);
	printf("\n");*/
	int q=f[l];
	if(q>=r-l+1) return -1;
	return tmp[l+q]<=tmp[q+1];
}
bool check(int x,int y,int len)
{
	for(int i=0;i<len;i++)
		if(sr[x+i]!=sr[y+i]) return 0;
	return 1;
}
int getans()
{
	for(int i=1;i<=n;i++)
		tmp[i]=sr[i];
	for(int i=1;i<=n;i++)
		tmp[n+i]=sr[i];
	int i=1,j=2,k=0;
	while(i<=n&&j<=n&&k<n)
	{
		//printf("i=%d,j=%d,k=%d\n",i,j,k);
		if(tmp[i+k]==tmp[j+k]) k++;
		else if(tmp[i+k]<tmp[j+k]) j+=k+1,k=0;
		else i+=k+1,k=0;
		if(i==j) i++;
	}
//	printf("i=%d,j=%d,k=%d\n",i,j,k);
	if(i<=n) return i;
	return j;
}
void upd(char *s,char *s2)
{
	if(strcmp(s+1,s2+1)>0)
	{
		for(int i=1;i<=n;i++)
			s[i]=s2[i];
	}
}
int main()
{
	//freopen("CF594E.in","r",stdin);
	//freopen("CF594E.out","w",stdout);
	scanf("%s%d",s+1,&k);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		sr[i]=s[n-i+1];
	if(k==1)
	{
		if(strcmp(s+1,sr+1)<=0) printf("%s",s+1);
		else printf("%s",sr+1);
		return 0;
	}
	for(int i=1;i<=n;)
	{
		int j=i,kk=i+1;
		while(kk<=n&&sr[j]<=sr[kk])
		{
			if(sr[j]==sr[kk]) j++;
			else j=i;
			kk++;
		}
		while(i<=j)
		{
			a[++at]=i;
			i+=(kk-j);
		}
	}
//	fprintf(stderr,"---\n");
	a[at+1]=n+1;
	int nw=1;
	b[++bt]=a[nw];
	d[bt]=a[nw+1]-a[nw];
	for(int i=2;i<=at;i++)
	{
		int len1=a[nw+1]-a[nw],len2=a[i+1]-a[i];
		if(len1!=len2||!check(a[nw],a[i],len1))
		{
			nw=i;
			b[++bt]=a[nw];
			d[bt]=len2;
		}
	}
//	fprintf(stderr,"---\n");
/*	printf("at=%d,bt=%d\n",at,bt);
	for(int i=1;i<=at;i++)
		printf("%d ",a[i]);
	printf("\n");
	for(int i=1;i<=bt;i++)
		printf("%d ",b[i]);
	printf("\n");
	for(int i=1;i<=bt;i++)
		printf("%d ",d[i]);
	printf("\n");*/
	while(k>=3)
	{
		//fprintf(stderr,"bt=%d,at=%d\n",bt,at);
		sr[n+1]=0;
		printf("%s",sr+b[bt]);
		if(d[bt]>1||d[bt-1]>1) k--;
		while(at&&a[at]>=b[bt]) at--;
		n=b[bt]-1;
		bt--;
		if(!bt) return 0;
	}
//	fprintf(stderr,"---\n");
	for(int i=1;i<=n;i++)
		s[i]=sr[n-i+1];
	s[n+1]=0;
	int q=getans();
	for(int i=q;i<=n;i++)
		ans1[++t1]=sr[i];
	for(int i=1;i<q;i++)
		ans1[++t1]=sr[i];
	exkmp();
	nw=n;
	for(int i=n-1;i>1;i--)
	{
		int q1=query(2*n-nw+2,2*n-i+1),q2=query(nw-i+1,nw);
	//	printf("nw=%d,i=%d,q1=%d,q2=%d\n",nw,i,q1,q2);
		if(q1==1||(q1==-1&&q2==0)) nw=i;
	}
//	fprintf(stderr,"---\n");
//	printf("nw=%d\n",nw);
	for(int i=n;i>=nw;i--)
		ans2[++t2]=sr[i];
	for(int i=1;i<nw;i++)
		ans2[++t2]=sr[i];
	int nw2=0;
	for(int i=bt;i>1;i--)
	{
		int fl=0;
		for(int j=b[i-1],k=b[i];j<=n;j++)
		{
			if(sr[j]!=sr[k])
			{
				if(sr[j]>sr[k]) fl=1;
			//	printf("i=%d,j=%d,k=%d\n",i,j,k);
				break;
			}
			if(k>=b[i]) k++;
			else k--;
			if(k>n) k=b[i]-1;
		}
		if(fl)
		{
			nw2=b[i];
			break;
		}
	}
//	fprintf(stderr,"---\n");
	if(!nw2) nw2=1;
//	printf("nw2=%d\n",nw2);
	for(int i=nw2;i<=n;i++)
		ans3[++t3]=sr[i];
	for(int i=nw2-1;i>=0;i--)
		ans3[++t3]=sr[i];
//	printf("\n%s\n%s\n%s\n%s\n",s+1,ans1+1,ans2+1,ans3+1);
	upd(s,ans1);
	upd(s,ans2);
	upd(s,ans3);
	printf("%s",s+1);
	return 0;
}