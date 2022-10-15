// Credit to robs77 for this template
/***********HEADER***************/
#include <iostream>
#include <bitset>
#include <iomanip>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <set>
#include <queue>
#include <map>
#include <cstdlib>
/***********MACROS***************/
//#define int long long 
#define ll  long long 
#define LL long long
#define fri(l,k) for (i=l;i<=k;i++)
#define frj(l,k) for (j=l;j>=k;j--)
#define fij(a,b,l,k) for(i=a;i<=b;i++) for(j=l;j<=k;j++)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define endl "\n"
#define pb push_back
#define _1 first
#define _2 second
#define mxsz 1000000007
#define mxval 1e9 + 7
#define grt [](auto x,auto y){return x>y;}
#define pii pair<int,int>
#define fi first 
#define se second 
#define mod 1000000007
#define inf 100000000
/*********VARIABLE****************/
using namespace std;
typedef pair<int,int> ii;
/******************************/
const int maxn=2e5+9;
char s[maxn];
/*********FUNCTIONS**************/

/***********MAIN**************/

signed main(){ 
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		while(n--)
		{
			scanf("%s",s);
			int num=0,flag=0,len=strlen(s);
			for(int i=0;i<len;i++)
			{
				if(s[i]>='A'&&s[i]<='Z')
				{
					num++;
				}
				if(i>0&&s[i]>='A'&&s[i]<='Z'&&s[i-1]>='A'&&s[i-1]<='Z') flag=1;
			}
			if(num==2&&!flag)
			{
				int row=0,j,col=0;
				for(int i=1;i<len;i++)
				{
					if(s[i]>='0'&&s[i]<='9')
					{
						row=row*10+s[i]-'0';
					}
					else 
					{
						j=i+1;
						break;
					}
				}
				for(int i=j;i<len;i++)
				{
					if(s[i]>='0'&&s[i]<='9')
					{
						col=col*10+s[i]-'0';
					}
				}
				char a[19];
				int k=0;
				while(col)
				{
					int temp=col%26;
					col/=26;
					if(temp) a[k++]=temp+'A'-1;
					else a[k++]='Z',col--;
				}
				for(int i=k-1;i>=0;i--)
				{
					printf("%c",a[i]);
				}
				printf("%d\n",row);
			}
			else 
			{
				int col=0,row=0;
				for(int i=0;i<len;i++)
				{
					if(s[i]>='A'&&s[i]<='Z')
					{
						col=col*26+s[i]-'A'+1;
					}
					else 
					{
						row=row*10+s[i]-'0';
					}
				}
				printf("R%dC%d\n",row,col);
			}
		}
	}
}