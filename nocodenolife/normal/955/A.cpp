#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int hh, m;
	cin>>hh>>m;
	int h,d,c,n;
	cin>>h>>d>>c>>n;

	long double answer1, answer2;
	if(hh<20)
	{
		int buns = (h+n-1)/n;
		answer1 = buns * c * 1.0;
		//cout<<buns<<endl;


		int time = (20-hh)*60 - m;
		h += (time*d);
		buns = (h+n-1)/n;
		answer2 = buns *c * 0.8;
		answer1 = answer1<answer2?answer1:answer2;
		cout<<setprecision(12)<<answer1;
	}
	else
	{
		int buns = (h+n-1)/n;
		answer1 = buns * c * 0.8;
		cout<<setprecision(12)<<answer1;	
	}


    return 0;
}