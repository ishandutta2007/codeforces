#include<cstdio>
#include<cstring>

int n,ans,an[1000001],la,anss;
char s[100001],t[100001],y;
bool bo;

void reverse(int x)
{
	if (x!=n-1) an[++an[0]]=n-x-1; an[++an[0]]=n;
	for (int i=0; i<=(x>>1); i++) y=s[i],s[i]=s[x-i],s[x-i]=y;
}

int main()
{
	scanf("%d",&n); scanf("%s%s",s,t); an[0]=0;
	for (int i=n-1; i>=0; i--)
		if (s[i]!=t[i])
		{
			ans=-1;
			for (int j=0; j<i; j++) if (s[j]==t[i]) {ans=j; break;}
			if (ans==-1) {printf("-1\n"); return 0;} 
			anss=10; if (i+1<anss) anss=i+1;
			for (int j=2; j<=10&&j<=i+1; j++)
			{
				la=ans; ans=-1;
				for (int k=0; k<=i-j+1; k++)
				{
					bo=1;
					for (int l=0; l<j; l++)
						if (s[k+l]!=t[i-j+l+1]) {bo=0; break;}
					if (bo) {ans=k+j-1; break;}
				}		
				if (ans==-1) {ans=la; anss=j-1; break;}
			}
			bo=1;
			for (int j=0; j<anss; j++)
				if (s[j]!=s[ans-j]) {bo=0; break;}
			if (!bo) reverse(ans); reverse(i);
		}
	printf("%d\n",an[0]);
	for (int i=1; i<=an[0]; i++) printf("%d ",an[i]);
	return 0;
}