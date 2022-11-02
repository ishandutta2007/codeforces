#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
char s[3][200010];
bool tag[3];
int n;
void work(char s1[],char s2[],bool typ)
{
	int t1=1,t2=1;
	for(;t1<=2*n||t2<=2*n;)
	{
		int num1=0,num2=0;
		for(;t1<=2*n&&s1[t1]-'0'!=typ;t1++,num1++);
		for(;t2<=2*n&&s2[t2]-'0'!=typ;t2++,num2++);
		rep(i,max(num1,num2))printf("%d",!typ);
		if(t1>2*n&&t2>2*n)break;
		printf("%d",typ);
		t1++;t2++;
	}
	puts("");
}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		for(int i=0;i<3;i++)
		{
			int cnt[2]={0,0};
			scanf("%s",s[i]+1);
			rep(j,2*n)cnt[s[i][j]-'0']++;
			tag[i]=cnt[1]>cnt[0];
		}
		if(tag[0]==tag[1])work(s[0],s[1],tag[0]);
		else if(tag[0]==tag[2])work(s[0],s[2],tag[0]);
		else work(s[1],s[2],tag[1]);
	}
	return 0;
}