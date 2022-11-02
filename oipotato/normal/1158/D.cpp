#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
struct Point
{
	int id,x,y;
	void scan(int _id){id=_id;scanf("%d%d",&x,&y);}
	friend Point operator-(const Point&a,const Point&b){return (Point){0,a.x-b.x,a.y-b.y};}
	friend LL operator*(const Point&a,const Point&b){return (LL)a.x*b.y-(LL)a.y*b.x;}
}p[2010];
char s[2010];
int n;
int main()
{
	scanf("%d",&n);
	rep(i,n)p[i].scan(i);
	scanf("%s",s+1);
	rep(i,n)if(p[i].y<p[1].y)swap(p[1],p[i]);
	rep(i,n-2)
	{
		int flag=s[i]=='L'?-1:1;
		for(int j=i+2;j<=n;j++)if((p[i+1]-p[i])*(p[j]-p[i])*flag>0)swap(p[i+1],p[j]);
	}
	rep(i,n)printf("%d%c",p[i].id," \n"[i==n]);
    return 0;
}