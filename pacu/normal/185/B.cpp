#include <iostream>
#include <iomanip>
using namespace std;

struct tp
{
	int exp,id;
	int ans;
};

bool cmp1(tp a,tp b)
{
	return a.exp>b.exp;
}

bool cmp2(tp a,tp b)
{
	return a.id<b.id;
}

int main()
{
	int S,a,b,c;
	cin >> S >> a >> b >> c;
	tp A[3];
	cout << setprecision(20);
	if((a+b+c)==0)
		cout << "0 0 0\n";
	else
		cout << ((double)S*a)/(a+b+c) << " "
		     << ((double)S*b)/(a+b+c) << " "
			 << ((double)S*c)/(a+b+c) << endl;
	return 0;
}