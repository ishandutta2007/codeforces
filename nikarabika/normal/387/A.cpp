#include <iostream>

using namespace std;
//11:30
//12:00
class Time
{
public:
	int hour, min;
	void build()
	{
		if(min<0)
		{
			hour--;
			min+=60;
		}
		if(hour<0)
		{
			hour+=24;
		}
	}
	
};

int main()
{
	Time a, b, c;
	char temp[5];
	int min, hour;
	
	cin>>temp;
	a.hour=(temp[0]-48)*10+temp[1]-48;
	a.min=(temp[3]-48)*10+temp[4]-48;
	
	cin>>temp;
	b.hour=(temp[0]-48)*10+temp[1]-48;
	b.min=(temp[3]-48)*10+temp[4]-48;
	
	c.hour=a.hour-b.hour;
	c.min=a.min-b.min;
	c.build();
	
	if(c.hour<10)
	{
		cout<<"0"<<c.hour<<":";
		if(c.min<10)
			cout<<"0"<<c.min<<endl;
		else 
			cout<<c.min<<endl;
	}
	else
	{
		if(c.min<10)
			cout<<c.hour<<":0"<<c.min<<endl;
		else
		cout<<c.hour<<":"<<c.min<<endl;
	}
	
	return 0;
}