#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#define s (l+r)/2
using namespace std;
int n,k,a[100007],m[100007];
int p[100007];
bool im[100007];
bool provera(int t)
{
	vector<int> q;
	fill(p,p+k+1,0);
	fill(im,im+k+1,false);
	int tn=k,brd=0;
	for(int i=t;i>=1;i--)
	{
		if(!im[m[i]]&&m[i]!=0)
		{
			im[m[i]]=true;
			tn--;
			p[m[i]]=i-1;
			q.push_back(m[i]);
		}
	}
	if(tn!=0) return false;
	for(int i=q.size()-1;i>=0;i--)
	{
		brd+=a[q[i]];
		if(brd>p[q[i]]) return false;
		brd++;
	}
	return true;
}
int binarna(int l,int r)
{
	if(provera(s)&&!provera(s-1)) return s;
	if(l==n) return -1;
	if(provera(s)) return binarna(l,s-1);
	return binarna(s+1,r);
}
int main(int argc, char** argv) 
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&m[i]);
	for(int i=1;i<=k;i++) scanf("%d",&a[i]);
	printf("%d",binarna(1,n));
	return 0;
}