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

int n,i,a[N],j;

set<pair<int,pair<int,int> > >st;

int Merger(int wt,int val,int t)
{
		set<pair<int,pair<int,int> > >::iterator it=st.lower_bound(mk(val,mk(wt,0)));
		if (it==st.end()) return t;
		if ((*it).fi==val&&(*it).se.fi==wt) 
		{
				int w=(*it).se.se;
				st.erase(it);
				return w;
		}
		return t;
}

int Mergel(int wt,int val,int t)
{
		set<pair<int,pair<int,int> > >::iterator it=st.upper_bound(mk(val,mk(wt,wt+1)));
		if (it==st.begin()) return t;
		--it;
		if ((*it).fi==val&&(*it).se.se==wt) 
		{
			int w=(*it).se.fi;
			st.erase(it); 
			return w;
		} 
		return t;
}

int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;++i) scanf("%d",&a[i]);
	a[0]=a[n+1]=(int)2e9; 
	for (i=1;i<=n;i=j)
	{
			for (j=i;j<=n&&a[i]==a[j];++j);
			st.insert(mk(a[i],mk(i,j-1)));
	}
	while (st.size()>1)
	{
			pair<int,pair<int,int> > x=*st.begin();
//			printf("%d\n",x.fi);
			st.erase(st.begin());
			int l=x.se.fi,r=x.se.se;
			if ((r-l+1)&1) 
			{
					puts("NO");
					return 0; 
			}
			x.fi=min(a[l-1],a[r+1]);
			l=Mergel(l-1,x.fi,l);
			r=Merger(r+1,x.fi,r);
//			printf("%d %d\n",l,r);
			st.insert(mk(x.fi,mk(l,r)));
	}
	puts("YES");
}