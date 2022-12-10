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

#define N 300005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k;

char c[5],s[5];

int main()
{
		scanf("%s",c);
		for (i=0;i<5;++i)
		{
				scanf("%s",s);
				if (s[0]==c[0]||s[1]==c[1]) break; 
		}
		if (i==5) puts("NO");
		else puts("YES"); 
}