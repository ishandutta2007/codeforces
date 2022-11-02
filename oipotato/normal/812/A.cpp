#include<cstdio>
using namespace std;
bool hit[10],p[10];
int l,s,r;
int main()
{
	scanf("%d%d%d%d",&l,&s,&r,&p[1]);
	if(l||s||r)hit[1]=1;
	if(l)hit[4]=1;
	if(s)hit[3]=1;
	if(r)hit[2]=1;
	scanf("%d%d%d%d",&l,&s,&r,&p[2]);
	if(l||s||r)hit[2]=1;
	if(l)hit[1]=1;
	if(s)hit[4]=1;
	if(r)hit[3]=1;
	scanf("%d%d%d%d",&l,&s,&r,&p[3]);
	if(l||s||r)hit[3]=1;
	if(l)hit[2]=1;
	if(s)hit[1]=1;
	if(r)hit[4]=1;
	scanf("%d%d%d%d",&l,&s,&r,&p[4]);
	if(l||s||r)hit[4]=1;
	if(l)hit[3]=1;
	if(s)hit[2]=1;
	if(r)hit[1]=1;
	if(p[1]&&hit[1]||p[2]&&hit[2]||p[3]&&hit[3]||p[4]&&hit[4])printf("YES");
	else printf("NO");
	return 0;
}