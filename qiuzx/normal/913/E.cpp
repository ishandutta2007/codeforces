#include <bits/stdc++.h>
using namespace std;
char s[10];
string ans[]={"!x&x","!(x|y|z)","!x&!y&z","!x&!y","!x&!z&y","!x&!z","!(!y&!z|x|y&z)","!(x|y&z)","!x&y&z","!(!y&z|!z&y|x)","!x&z","!(!z&y|x)","!x&y","!(!y&z|x)","!x&(y|z)","!x","!y&!z&x","!y&!z","!(!x&!z|x&z|y)","!(x&z|y)","!(!x&!y|x&y|z)","!(x&y|z)","!(!x&!y|x&y|z)|!x&!y&z","!((x|y)&z|x&y)","!x&y&z|!y&!z&x","!x&y&z|!y&!z","!x&z|!y&!z&x","!x&z|!y&!z","!x&y|!y&!z&x","!x&y|!y&!z","!x&(y|z)|!y&!z&x","!x|!y&!z","!y&x&z","!(!x&z|!z&x|y)","!y&z","!(!z&x|y)","!x&!z&y|!y&x&z","!x&!z|!y&x&z","!x&!z&y|!y&z","!x&!z|!y&z","!x&y&z|!y&x&z","!(!x&z|!z&x|y)|!x&y&z","!(x&y)&z","!(!z&x|y)|!x&z","!x&y|!y&x&z","!(!y&z|x)|!y&x&z","!x&y|!y&z","!x|!y&z","!y&x","!(!x&z|y)","!y&(x|z)","!y","!x&!z&y|!y&x","!x&!z|!y&x","!x&!z&y|!y&(x|z)","!x&!z|!y","!x&y&z|!y&x","!(!x&z|y)|!x&y&z","!x&z|!y&x","!x&z|!y","!x&y|!y&x","!(!x&!y&z|x&y)","!x&(y|z)|!y&x","!x|!y","!z&x&y","!(!x&y|!y&x|z)","!x&!y&z|!z&x&y","!x&!y|!z&x&y","!z&y","!(!y&x|z)","!x&!y&z|!z&y","!x&!y|!z&y","!x&y&z|!z&x&y","!(!x&y|!y&x|z)|!x&y&z","!x&z|!z&x&y","!(!z&y|x)|!z&x&y","!(x&z)&y","!(!y&x|z)|!x&y","!x&z|!z&y","!x|!z&y","!z&x","!(!x&y|z)","!x&!y&z|!z&x","!x&!y|!z&x","!z&(x|y)","!z","!x&!y&z|!z&(x|y)","!x&!y|!z","!x&y&z|!z&x","!(!x&y|z)|!x&y&z","!x&z|!z&x","!(!x&!z&y|x&z)","!x&y|!z&x","!x&y|!z","!x&(y|z)|!z&x","!x|!z","!y&x&z|!z&x&y","!(!x&y|!y&x|z)|!y&x&z","!y&z|!z&x&y","!(!z&x|y)|!z&x&y","!y&x&z|!z&y","!(!y&x|z)|!y&x&z","!y&z|!z&y","!(!y&!z&x|y&z)","!x&y&z|!y&x&z|!z&x&y","!(!x&y|!y&x|z)|!x&y&z|!y&x&z","!(x&y)&z|!z&x&y","!(!z&x|y)|!x&z|!z&x&y","!(x&z)&y|!y&x&z","!(!y&x|z)|!x&y|!y&x&z","!(x&y)&z|!z&y","!x|!y&z|!z&y","!(y&z)&x","!(!x&y|z)|!y&x","!y&z|!z&x","!y|!z&x","!y&x|!z&y","!y&x|!z","!y&(x|z)|!z&y","!y|!z","!(y&z)&x|!x&y&z","!(!x&y|z)|!x&y&z|!y&x","!(x&y)&z|!z&x","!x&z|!y|!z&x","!(x&z)&y|!y&x","!x&y|!y&x|!z","!x&y|!y&z|!z&x","!(x&y&z)","x&y&z","!(x|y|z)|x&y&z","!x&!y&z|x&y&z","!x&!y|x&y&z","!x&!z&y|x&y&z","!x&!z|x&y&z","!(!y&!z|x|y&z)|x&y&z","!(x|y&z)|x&y&z","y&z","!(x|y|z)|y&z","!x&z|y&z","!x&!y|y&z","!x&y|y&z","!x&!z|y&z","!x&(y|z)|y&z","!x|y&z","!y&!z&x|x&y&z","!y&!z|x&y&z","!(!x&!z|x&z|y)|x&y&z","!(x&z|y)|x&y&z","!(!x&!y|x&y|z)|x&y&z","!(x&y|z)|x&y&z","!(!x&!y|x&y|z)|!x&!y&z|x&y&z","!((x|y)&z|x&y)|x&y&z","!y&!z&x|y&z","!y&!z|y&z","!x&z|!y&!z&x|y&z","!(x&z|y)|y&z","!x&y|!y&!z&x|y&z","!(x&y|z)|y&z","!x&(y|z)|!y&!z&x|y&z","!x|!y&!z|y&z","x&z","!(x|y|z)|x&z","!y&z|x&z","!x&!y|x&z","!x&!z&y|x&z","!x&!z|x&z","!x&!z&y|!y&z|x&z","!(x|y&z)|x&z","(x|y)&z","!(x|y|z)|(x|y)&z","z","!x&!y|z","!x&y|x&z","!(!y&z|x)|x&z","!x&y|z","!x|z","!y&x|x&z","!y&!z|x&z","!y&(x|z)|x&z","!y|x&z","!x&!z&y|!y&x|x&z","!(x&y|z)|x&z","!x&!z&y|!y&(x|z)|x&z","!x&!z|!y|x&z","!y&x|y&z","!(!x&z|y)|y&z","!y&x|z","!y|z","!x&y|!y&x|x&z","!x&!z|!y&x|y&z","!x&y|!y&x|z","!x|!y|z","x&y","!(x|y|z)|x&y","!x&!y&z|x&y","!x&!y|x&y","!z&y|x&y","!x&!z|x&y","!x&!y&z|!z&y|x&y","!(x|y&z)|x&y","(x|z)&y","!(x|y|z)|(x|z)&y","!x&z|x&y","!(!z&y|x)|x&y","y","!x&!z|y","!x&z|y","!x|y","!z&x|x&y","!y&!z|x&y","!x&!y&z|!z&x|x&y","!(x&z|y)|x&y","!z&(x|y)|x&y","!z|x&y","!x&!y&z|!z&(x|y)|x&y","!x&!y|!z|x&y","!z&x|y&z","!(!x&y|z)|y&z","!x&z|!z&x|x&y","!x&!y|!z&x|y&z","!z&x|y","!z|y","!x&z|!z&x|y","!x|!z|y","(y|z)&x","!(x|y|z)|(y|z)&x","!y&z|x&y","!(!z&x|y)|x&y","!z&y|x&z","!(!y&x|z)|x&z","!y&z|!z&y|x&y","!x&!y|!z&y|x&z","(x|y)&z|x&y","!(x|y|z)|(x|y)&z|x&y","x&y|z","!x&!y|x&y|z","x&z|y","!x&!z|x&z|y","y|z","!x|y|z","x","!y&!z|x","!y&z|x","!y|x","!z&y|x","!z|x","!y&z|!z&y|x","!y|!z|x","x|y&z","!y&!z|x|y&z","x|z","!y|x|z","x|y","!z|x|y","x|y|z","!x|x"};
int main(){
	int i,t,mask;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",&s);
		mask=0;
		for(i=0;i<8;i++)
		{
			if(s[i]=='1')
			{
				mask|=(1<<i);
			}
		}
		printf("%s\n",ans[mask].c_str());
	}
	return 0;
}