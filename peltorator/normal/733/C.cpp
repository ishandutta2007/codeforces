#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <queue>
using namespace std;

typedef long long LL;
typedef pair<int,int> mp;
#define pb push_back
const int maxn = 100005;

LL a[maxn],b[maxn];
int n,m,l[maxn],r[maxn];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("monstropolis.in","r",stdin);
		freopen("monstropolis.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
		scanf("%lld",&b[i]);
	for (int i=1;i<=m;i++) {
		l[i]=r[i-1]+1;r[i]=l[i]-1;
		LL sum=0;
		while (sum<b[i]&&r[i]<n) {
			sum+=a[++r[i]];
		}
//		cerr<<l[i]<<" "<<r[i]<<" "<<sum<<endl;
		if (sum!=b[i]) {puts("NO");return 0;}
		if (r[i]>n) {puts("NO");return 0;}
		bool tag=true;
		for (int j=l[i];j<=r[i];j++)
		if (a[j]!=a[l[i]]) tag=false;
		if (tag&&l[i]!=r[i]) {puts("NO");return 0;}
	}
	if (r[m]!=n) {puts("NO");return 0;}
	puts("YES");
	for (int i=1;i<=m;i++)
	if (l[i]!=r[i]) {
		int pos=0;
		for (int j=l[i];j<=r[i];j++) {
			bool tag=false;
			if (j>l[i]&&a[j-1]<a[j]) tag=true;
			if (j<r[i]&&a[j+1]<a[j]) tag=true;
			if (tag) {
				if (a[j]>a[pos]) pos=j;
			}
		}
		if (pos==l[i]) {
			for (int j=l[i]+1;j<=r[i];j++)
				printf("%d R\n",i);
		}
		else if (pos==r[i]) {
			for (int j=r[i];j>l[i];j--)
				printf("%d L\n",i+j-l[i]);
		}
		else if (a[pos-1]<a[pos+1]) {
			for (int j=pos;j>l[i];j--)
				printf("%d L\n",i+j-l[i]);
			for (int j=pos+1;j<=r[i];j++)
				printf("%d R\n",i);
		}
		else {
			for (int j=pos+1;j<=r[i];j++)
				printf("%d R\n",i+pos-l[i]);
			for (int j=pos;j>l[i];j--)
				printf("%d L\n",i+j-l[i]);
		}
	}	
	return 0;
}