#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 3000005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k,len,flag[26],vis[26],Vis[26],Flag[26];

char c[N],a[N],b[N];

void Output()
{
		for (i=0;i<k;++i)
			if (vis[i]==-1)
			{
					for (j=0;j<k;++j) if (!flag[j]) 
					{
							flag[j]=1; vis[i]=j;
							break; 
					}
			}
		puts("YES");
		for (i=0;i<k;++i) printf("%c",vis[i]+'a');
		puts("");
}

int Maxinum(int st)
{
		int i;
		for (i=0;i<k;++i) Vis[i]=vis[i],Flag[i]=flag[i];
		for (i=st;i<=len;++i)
			if (Vis[c[i]-'a']==-1) 
			{
					for (j=k-1;j>=0;--j) if (!Flag[j]) break;
					Vis[c[i]-'a']=j;
					Flag[j]=1;
			}
		for (i=1;i<=len;++i) if (Vis[c[i]-'a']+'a'!=a[i]) break;
		if (i<=len&&Vis[c[i]-'a']+'a'<a[i]) return 0;
		for (i=1;i<=len;++i) if (Vis[c[i]-'a']+'a'!=b[i]) break;
		if (i<=len&&Vis[c[i]-'a']+'a'>b[i]) return 0;
		for (i=0;i<k;++i) vis[i]=Vis[i],flag[i]=Flag[i];
		Output();
		return 1;		 
}

int Mininum(int st)
{
		int i;
		for (i=0;i<k;++i) Vis[i]=vis[i],Flag[i]=flag[i];
		for (i=st;i<=len;++i)
			if (Vis[c[i]-'a']==-1) 
			{
					for (j=0;j<k;++j) if (!Flag[j]) break;
					Vis[c[i]-'a']=j;
					Flag[j]=1;
			}
		for (i=1;i<=len;++i) if (Vis[c[i]-'a']+'a'!=a[i]) break;
		if (i<=len&&Vis[c[i]-'a']+'a'<a[i]) return 0;
		for (i=1;i<=len;++i) if (Vis[c[i]-'a']+'a'!=b[i]) break;
		if (i<=len&&Vis[c[i]-'a']+'a'>b[i]) return 0;
		for (i=0;i<k;++i) vis[i]=Vis[i],flag[i]=Flag[i];
		Output();
		return 1;		 
}

void Main()
{
				scanf("%d",&k);
				scanf("%s",c+1);
				scanf("%s",a+1);
				scanf("%s",b+1);
				len=strlen(c+1);
				for (i=1;i<=len;++i) if (a[i]!=b[i]) break;
				if (i<=len&&a[i]>b[i])
				{
						puts("NO");
						return;
				}
				for (i=0;i<k;++i) vis[i]=-1,flag[i]=0;
				for (i=1;i<=len;++i)
					if (vis[c[i]-'a']!=-1)
					{
							if (vis[c[i]-'a']<a[i]-'a'||vis[c[i]-'a']>b[i]-'a') 
							{
									puts("NO");
									return;
							}
							if (a[i]-'a'<vis[c[i]-'a']&&vis[c[i]-'a']<b[i]-'a')
							{
									Output();
									return; 
							}
							if (a[i]!=b[i])
							{
									if (Maxinum(i+1)) return;
									if (Mininum(i+1)) return;
									puts("NO");
									return;
							}
					}
					else
					{
							if (a[i]==b[i])
							{
									vis[c[i]-'a']=a[i]-'a';
									if (flag[a[i]-'a']) 
									{
											puts("NO");
											return;
									}
									flag[a[i]-'a']=1;
							}
							else
							{
									for (j=a[i]-'a'+1;j<=b[i]-'a'-1;++j) if (!flag[j])
									{
											vis[c[i]-'a']=j;
											flag[j]=1;
											Output();
											return;
									}
									if (!flag[a[i]-'a'])
									{
											vis[c[i]-'a']=a[i]-'a';
											flag[a[i]-'a']=1;
											if (Maxinum(i+1)) return;
											flag[a[i]-'a']=0;
									}
									if (!flag[b[i]-'a'])
									{
											vis[c[i]-'a']=b[i]-'a';
											flag[b[i]-'a']=1;
											if (Mininum(i+1)) return;
									}
									puts("NO");
									return;
							}
					}
				if (i>len) Output(); 
}

int main()
{
		int T;
		scanf("%d",&T);
		for (;T--;) Main();
}