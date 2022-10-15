#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//

int n,m,seed=314159;
long long h1[400010],h2[400010],pw[400010];
char a[400010];
 
int check(int i,int l)
{if(i<l) return 0;
 return h1[i]-h1[i-(l+1)/2]*pw[(l+1)/2]==h2[i-l+1]-h2[i-l/2+1]*pw[(l+1)/2];
}
 
int check2(int i,int l)
{if(i<l) return 0;
 return (h1[i]-h1[i-(l+1)/2]*pw[(l+1)/2])*pw[i-l+1]==h2[i-l/2]-h2[i-l];
}
 
int main()
{int i,j,i1,k,flag,flag1;
 
 scanf("%d",&m);
 scanf("%s",a+1);
 n=strlen(a+1);
 pw[0]=1;
 for(i=1;i<=n;i++) pw[i]=pw[i-1]*seed;
 for(i=1;i<=n;i++)
 	h1[i]=h1[i-1]*seed+a[i]-96;
 for(i=n;i>=1;i--)
 	h2[i]=h2[i+1]*seed+a[i]-96;	
 k=0;
 for(i=1;i<=n;i++)
 {	flag1=check(i,m) || check(i,m+1);
 	flag=0;
	for(i1=a[i]+1;i1<=122;i1++)
	{	flag=1;
		if(i>=m && i1==a[i-m+1] && check(i-1,m-2)) flag=0;
		if(i>=m+1 && i1==a[i-m] && check(i-1,m-1)) flag=0;
		if(flag) break;
	}
	if(flag1)
	{	if(flag) k=i;
		break;
	}
	else if(flag)
		k=i;
 }
 if(!k || m==1)
 {	printf("Impossible\n");
 	return 0;
 }
 for(i=k+1;i<=n;i++) a[i]=96;
 for(i=1;i<=k;i++)
 	h2[i]=h2[i-1]+(a[i]-96)*pw[i];
 for(;k<=n;k++)
 {	a[k]++;
 	h1[k]=h1[k-1]*seed+a[k]-96;
 	h2[k]=h2[k-1]+(a[k]-96)*pw[k];
 	while(a[k]<=122 && (check2(k,m) || check2(k,m+1)))
 	{	a[k]++;
 		h1[k]=h1[k-1]*seed+a[k]-96;
 		h2[k]=h2[k-1]+(a[k]-96)*pw[k];
 	}
 	if(a[k]==123)
 	{	a[k]=96;
 		k--;
 	}
 }
 for(i=1;i<=n;i++)
 	printf("%c",a[i]);
 return 0;
}