#include <bits/stdc++.h>
#define N 60
using namespace std;
int x[N],y[N],n;
bool check(int p)
{
	int i;
	int tp=100,lt=100,rt=-100,dw=-100;
	for(i=0;i<4*n+1;i++)
	{
		if(i!=p)
		{
			tp=min(tp,x[i]);
			lt=min(lt,y[i]);
			rt=max(rt,y[i]);
			dw=max(dw,x[i]);
		}
	}
	if(dw-tp!=rt-lt)
	{
		return false;
	}
	for(i=0;i<4*n+1;i++)
	{
		if(i!=p)
		{
			if(x[i]!=tp&&x[i]!=dw&&y[i]!=lt&&y[i]!=rt)
			{
				return false;
			}
		}
	}
	return true;
}
int main(){
	int i;
	cin>>n;
	for(i=0;i<4*n+1;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(i=0;i<4*n+1;i++)
	{
		if(check(i))
		{
			cout<<x[i]<<" "<<y[i]<<endl;
		}
	}
	return 0;
}