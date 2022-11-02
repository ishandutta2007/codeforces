#include <bits/stdc++.h>
#define MAXN 100007
using namespace std;
int a[MAXN];
int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		bool gotov=false,imak=false;
		int n,k; scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		if(n==1 && a[0]==k) {gotov=true;}
		for(int i=0;i<n;i++) if(a[i]==k) imak=true;
		for(int i=0;i<n-1;i++) if(a[i]==k && a[i+1]>=k) {gotov=true; break;}
		for(int i=1;i<n;i++) if(a[i]==k && a[i-1]>=k) {gotov=true; break;}
		for(int i=0;i<n-2;i++) if(a[i]==k && a[i+1]<k && a[i+2]==k) {gotov=true; break;}
		if(imak) for(int i=0;i<n-1;i++) if(a[i]>=k && a[i+1]>=k) {gotov=true; break;}
		if(imak) for(int i=0;i<n-2;i++) if(a[i]>=k && a[i+1]<k && a[i+2]>=k) {gotov=true; break;}
		if(gotov) {printf("yes\n"); continue;}
		int cursum=-1000000000;
		for(int i=0;i<n;i++)
		{
			if(a[i]<k) cursum--;
			if(a[i]>=k) cursum++;
			if(cursum==0) gotov=true;
			if(a[i]==k) cursum=0;
		}
		cursum=-1000000000;
		for(int i=n-1;i>=0;i--)
		{
			if(a[i]<k) cursum--;
			if(a[i]>=k) cursum++;
			if(cursum==0) gotov=true;
			if(a[i]==k) cursum=0;
		}
		if(gotov) {printf("yes\n"); continue;}
		printf("no\n");
	}
}