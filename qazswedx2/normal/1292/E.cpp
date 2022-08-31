#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
//#define DEBUG
int t,n;
char s[55],str[55],tt[55];
double nw;
int query(const char *a,int qwq=-1)
{
#ifdef DEBUG
//	printf("? %s\n",a);
	int l=strlen(a),k=0,ffl=0;
	nw+=1.0/l/l;
	strcpy(tt,a);
	for(int i=1;i+l-1<=n;i++)
	{
		int fl=1;
	//	printf("i=%d\n",i);
		for(int j=0;j<l;j++)
			if(tt[j]!=str[i+j])
				fl=0;
		if(fl)
		{
			if(qwq==i) ffl=1;
			k++;
			for(int j=i,ll=0;ll<l;j++,ll++)
			{
				s[j]=tt[ll];
				//printf("k=%d,l=%d\n",j,l);
			}
		}
	}
	if(qwq!=-1) return ffl;
//	printf("k=%d\n",k);
	return k;
#else
	printf("? %s\n",a);
	fflush(stdout);
	strcpy(tt,a);
	int k,len=strlen(a),ffl=0;
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
	{
		int x;
		scanf("%d",&x);
		if(qwq!=-1&&x==qwq) ffl=1;
		for(int j=x,l=0;l<len;j++,l++)
			s[j]=tt[l];
	}
	if(qwq!=-1) return ffl;
	return k;
#endif
}
//#define query(x) (printf("line=%d:",__LINE__),qquery(x))
int ctt=0;
void print(const char *s)
{
	printf("! %s\n",s);
	fflush(stdout);
	int x;
#ifndef DEBUG
	scanf("%d",&x);
#else
	if(nw>1.4||strcmp(s,str+1))
	{
		printf("WA nw=%f,s=%s,str=%s\n",nw,s,str+1);
		exit(0);
	}
	ctt++;
	if(ctt%100==0) printf("ok,ctt=%d\n",ctt);
#endif
}
int main()
{
//	freopen("CF1292E.in","r",stdin);
	scanf("%d",&t);
	while(t--)
	{
		memset(s,0,sizeof(s));
		scanf("%d",&n);
#ifdef DEBUG
		nw=0;
		scanf("%s",str+1);
#endif
		query("HO");
		query("CO");
		query("CH");
		query("HC");
		int fl=0;
		for(int i=1;i<=n;i++)
			if(s[i]) fl=1;
		if(!fl)
		{
			query("CCC");
			query("HHH");
			for(int i=1;i<=n;i++)
				if(s[i]) fl=1;
			if(fl)
			{
				for(int i=1;i<=n;i++)
					if(!s[i]) s[i]='O';
				print(s+1);
				continue;
			}
			query("OOO");
			for(int i=1;i<=n;i++)
				if(s[i]) fl=1;
			if(fl)
			{
				for(int i=1;i<=n;i++)
					if(!s[i]) s[i]='C';
				if(!query(s+1))
				{
					for(int i=1;i<=n;i++)
						if(s[i]=='C') s[i]='H';
				}
				print(s+1);
				continue;
			}
			if(query("OOCC")) print("OOCC");
			else print("OOHH");
			continue;
		}
		if(!s[1])
		{
			int id=0;
			for(int i=1;i<=n;i++)
				if(s[i])
				{
					id=i;
					break;
				}
			for(int i=id-1;i>0;i--)
			{
				s[i]=s[i+1];
				if(!query(s+i,i))
				{
					for(int j=1;j<=i;j++)
						s[j]='O';
					break;
				}
			}
		}
		int l=1;
		while(l<n&&s[l+1]) l++;
		while(l<n)
		{
			int r=l+1;
			while(r<n&&!s[r+1]) r++;
			if(r<n)
			{
				for(int i=l+1;i<=r;i++)
				{
					s[i]='O';
					if(!query(s+1,1))
					{
						for(int j=i;j<=r;j++)
							s[j]=s[r+1];
						break;
					}
				}
			}
			else
			{
				for(int i=l+1;i<=r;i++)
				{
					s[i]='O';
					if(!query(s+1,1))
					{
						for(int j=i;j<=r;j++)
							s[j]='C';
						if(!query(s+1,1))
						{
							for(int j=i;j<=r;j++)
								s[j]='H';
						}
						break;
					}
				}
			}
			while(l<n&&s[l+1]) l++;
		}
		print(s+1);
	}
	return 0;
}