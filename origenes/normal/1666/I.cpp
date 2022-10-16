#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int s1,s2,s3,s4,s5;
		int sx,sy,dx,dy;
		int x1,x2,y1,y2;
		cout<<"SCAN "<<1<<' '<<1<<endl;
		cin>>s1;
		cout<<"SCAN "<<1<<' '<<m<<endl;
		cin>>s3;
		sx=(s1+s3+6-2*m)/2;
		sy=(s1-s3+2+2*m)/2;
		cout<<"SCAN "<<1<<' '<<sy/2<<endl;
		cin>>s4;
		cout<<"SCAN "<<sx/2<<' '<<1<<endl;
		cin>>s5;
		dy=s4-sx+2;
		dx=s5-sy+2;
		y2=(dy+sy)/2;
		y1=(sy-dy)/2;
		x2=(dx+sx)/2;
		x1=(sx-dx)/2;
		int usl;
		cout<<"DIG "<<x1<<' '<<y1<<endl;
		cin>>usl;
		if(usl==0)
		{
			swap(x1,x2); 
		}
		cout<<"DIG "<<x1<<' '<<y1<<endl;
		cin>>usl;
		cout<<"DIG "<<x2<<' '<<y2<<endl;
		cin>>usl;
		continue;
	}
}