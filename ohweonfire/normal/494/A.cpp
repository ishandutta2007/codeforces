#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100005;
char s[maxn];
int len,ans[maxn];
int getlast()
{
	for(int i=len-1;i>=0;i--)
		if(s[i]=='#')
			return i;
	return -1;
}
int main()
{
	scanf("%s",s);
	len=strlen(s);
	int last=getlast(),tmp=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='(')
			tmp++;
		else if(s[i]==')')
			tmp--;
		else
		{
			if(i!=last)
			{
				ans[i]=1;
				tmp--;
			}
			else
			{
				if(tmp<1){
					puts("-1");
					return 0;
				}
				ans[i]=tmp;
				tmp=0;
			}
		}
		if(tmp<0&&i<=last){
			puts("-1");
			return 0;
		}
	}
	if(last!=-1&&-tmp>=ans[last])
	{
		puts("-1");
		return 0;
	}
	if(last>=0)ans[last]+=tmp;
	tmp=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='(')
			tmp++;
		else if(s[i]==')')
			tmp--;
		else
			tmp-=ans[i];
		if(tmp<0)
		{
			puts("-1");
			return 0;
		}
	}
	if(tmp)
	{
		puts("-1");
		return 0;
	}
	for(int i=0;i<len;i++)if(ans[i]!=0)printf("%d\n",ans[i]);
	return 0;
}