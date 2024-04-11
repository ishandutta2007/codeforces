#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
int h;
LL n,ans;
bool move(int height,LL &q)
{
	int cnt=0;
	LL tmp=q;
	while(tmp)
	{
		cnt++;
		tmp>>=1;
	}
	tmp=q>>(cnt-2);
	if(tmp==2)
	{
		q-=1ll<<cnt-2;
		return true;
	}
	else
	{
		q-=1ll<<cnt-1;
		return false;
	}
}
void dfs(int height,LL q,bool left)
{
	ans++;
	if(height==1||q==1)return;
	LL t=(1ll<<height-1)-1;
	bool l=move(height,q);
	ans+=(l!=left)*t;
	dfs(height-1,q,!l);
}
int main()
{
	cin>>h>>n;
	n+=(1ll<<h)-1;
	h++;
	dfs(h,n,1);
	cout<<ans-1<<endl;
	return 0;
}
/*50 1125899906842624*/