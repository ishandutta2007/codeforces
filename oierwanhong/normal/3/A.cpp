#include<iostream>
#include<cstdio>
typedef long long ll;
const ll INF=1ll<<60;
struct one
{
	ll x,y;
}s,t;
ll dx,dy;
char cx,cy;
void start()
{
	s.x=getchar()-'a';
	s.y=getchar()-'1';
	getchar();
	t.x=getchar()-'a';
	t.y=getchar()-'1';
	dx=t.x-s.x,dy=t.y-s.y;
	if(dx>0)cx='R';
	else dx=-dx,cx='L';
	if(dy>0)cy='U';
	else dy=-dy,cy='D';
	std::cout<<std::max(dx,dy)<<std::endl;
}
int main()
{
	start();
	while(dx||dy)
	{
		if(dx)
		{
			--dx;putchar(cx);
		}
		if(dy)
		{
			--dy;putchar(cy);
		}
		putchar('\n');
	}
	return 0;
}