#include<algorithm>
#include<iomanip>
#include<iostream>
using namespace std;

long long a,b,p[35];
int u,v;
double a1,a2;

int main(){
	cin >> a >> b;
	if(a<b){cout << -1 << endl; return 0;}
	if(a==b){cout << b << ".000000000" << endl; return 0;}
	u=(a-b)/(2*b);
	v=(a+b)/(2*b);
	if(u>0)a1=(double)(a-b)/(2*u); else a1=b;
	a2=(double)(a+b)/(2*v);
	//cout << u << " " << v << endl;
	//cout << a1 << " " << a2 << endl;
	if(u==0)cout << setprecision(9) << fixed << a2 << endl;
	else cout << setprecision(9) << fixed << min(a1,a2) << endl;
	return 0;
}