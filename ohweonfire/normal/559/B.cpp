#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long uLL;
const int maxn=200005;
char a[maxn],b[maxn];
int n;
bool check(int la,int lb,int ra,int rb)
{
	bool same=true;
	for(int i=la,j=ra;i<=lb&&same;i++,j++)same&=(a[i]==b[j]);
	if(same)return true;
	if(((la+lb)&1)==0)return false;
	int ml=la+lb>>1,mr=ra+rb>>1;
	if(check(la,ml,ra,mr)&&check(ml+1,lb,mr+1,rb))return true;
	return check(ml+1,lb,ra,mr)&&check(la,ml,mr+1,rb);
}
int main()
{
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1);
	puts(check(1,n,1,n)?"YES":"NO");
	return 0;
}