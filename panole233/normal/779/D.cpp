#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define ref(i,x,y)for(int i=x;i<=y;++i)
char a[200002],b[200002];
int lena,lenb;
int p[200002];
bool B[200002];
bool check(int s)
{
	memset(B,0,sizeof B);
	ref(i,1,s)B[p[i]]=1;
	for(int i=1,j=1;i<=lena;i++)
	{
		while(i<=lena&&B[i])i++;
		if(i>lena)break;
		if(a[i]==b[j])j++;
		if(j>lenb)return 1;
	}
	return 0;
}
int main()
{
	scanf("%s%s",a+1,b+1);
	lena=strlen(a+1),lenb=strlen(b+1);
	ref(i,1,lena)scanf("%d",&p[i]);
	int l,r,mid;
	for(l=0,r=lena;l<r;)
	{
		mid=(l+r+1)>>1;
		if(check(mid))l=mid;else r=mid-1;
	}
	cout<<l<<endl;
}