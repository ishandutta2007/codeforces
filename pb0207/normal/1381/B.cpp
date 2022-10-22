#include<bits/stdc++.h>
using namespace std;

const int N=2e3+1e2+7;

int T;

int f[N],n,p[N*2+1];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

vector<pii>v;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++)
			scanf("%d",&p[i]);
		v.clear();
		for(int i=1,j;i<=n*2;i=j+1)
		{
			j=i;
			while(p[j+1]<p[i]&&j+1<=n*2)
				j++;
			v.push_back(mp(i,j));
		}
		for(int i=0;i<=n;i++)
			f[i]=0;
		f[0]=1;
		for(int i=0;i<v.size();i++)
			for(int j=n;j>=v[i].sd-v[i].fs+1;j--)
				f[j]|=f[j-(v[i].sd-v[i].fs+1)];
		if(f[n])
			puts("YES");
		else
			puts("NO");
	}
}