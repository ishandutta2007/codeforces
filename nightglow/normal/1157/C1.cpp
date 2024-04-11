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

int i,j,m,n,p,k,a[N];

string s;

int main()
{
		scanf("%d",&n);
		for (i=1;i<=n;++i) scanf("%d",&a[i]);
		int L=1,R=n,now=0;
		while (L<=R)
		{
				if (a[L]<=now&&a[R]<=now) break;
				if (a[L]<=now) s+='R',now=a[R],R--;
				else if (a[R]<=now) s+='L',now=a[L],L++;
				else if (a[L]<a[R]) s+='L',now=a[L],L++;
				else if (a[L]>a[R]) s+='R',now=a[R],R--;
				else
				{
						for (j=L+1;j<=R;++j) if (a[j]<=a[j-1]) break;
						for (k=R-1;k>=L;--k) if (a[k]<=a[k+1]) break;
						if (j-L<=R-k) 
						for (i=1;i<=R-k;++i) s+='R'; 
						else for (i=1;i<=j-L;++j) s+='L';
						break;
				}
		}
		printf("%d\n",(int)s.size());
		cout<<s<<endl;
}