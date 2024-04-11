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

multiset<int>st;

int main()
{
		scanf("%d",&n);
		for (i=1;i<=n;++i) scanf("%d",&a[i]);
		for (i=1;i<=n;++i) scanf("%d",&p),st.insert(p);
		for (i=1;i<=n;++i)
		{
				set<int>::iterator it=st.lower_bound(n-a[i]);
				if (it==st.end()) it=st.begin();
				printf("%d ",(a[i]+*it)%n);
				st.erase(it);
		}
}