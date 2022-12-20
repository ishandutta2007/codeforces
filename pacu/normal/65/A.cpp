#include <iostream>
using namespace std;

int main()
{
	int a,b,c,d,e,f;
	cin >> a >> b >> c >> d >> e >> f;
	if(d==0)
		cout << "Hermione";
	else if(c==0)
		cout << "Ron";
	else if(b==0)
		cout << "Hermione";
	else if(a==0)
		cout << "Ron";
	else if(f==0)
		cout << "Hermione";
	else if(e==0)
		cout << "Ron";
	else
		cout << ((((double)(b*d*f))/((double)(a*c*e))>1.0)?"Ron":"Hermione") << endl;;
	return 0;
}