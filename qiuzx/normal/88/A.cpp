#include <bits/stdc++.h>
using namespace std;
void check(int a,int b,int c)
{
	if((a+4)%12==b&&(b+3)%12==c)
	{
		cout<<"major"<<endl;
		exit(0);
	}
	if((a+3)%12==b&&(b+4)%12==c)
	{
		cout<<"minor"<<endl;
		exit(0);
	}
}
int main(){
	string x,y,z,ch[12]={"C","C#","D","D#","E","F","F#","G","G#","A","B","H"};
	int a,b,c,i; 
	cin>>x>>y>>z;
	for(i=0;i<12;i++)
	{
		if(ch[i]==x)
		{
			a=i;
		}
		else if(ch[i]==y)
		{
			b=i;
		}
		else if(ch[i]==z)
		{
			c=i;
		}
	}
	check(a,b,c);
	check(a,c,b);
	check(b,a,c);
	check(b,c,a);
	check(c,a,b);
	check(c,b,a);
	cout<<"strange"<<endl;
}