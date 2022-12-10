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

#define N 500005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k,ans;

map<int,int>mp,gw;

char c[N];

int main()
{
		scanf("%d",&n);
		for (i=1;i<=n;++i)
		{
				scanf("%s",c+1);
				int len=strlen(c+1),top=0,cnt=0;
				for (j=1;j<=len;++j)
					if (c[j]==')')
					{
							if (top==0) cnt++;
							else top--;
					}
					else top++;
				if (top>0&&cnt>0) continue;
				if (top==0&&cnt==0) 
				{
						if (mp[0]>0) mp[0]--,ans++;
						else mp[0]++; 
				}
				else if (top>0) 
				{
						if (gw[top]>0) gw[top]--,ans++;
						else
						mp[top]++;
				}
				else 
				{
						if (mp[cnt]>0) mp[cnt]--,++ans;
						else gw[cnt]++;
				}
		}
		printf("%d\n",ans); 
}