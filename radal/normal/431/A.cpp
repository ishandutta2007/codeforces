#include <iostream>
using namespace std;
int main()
{
	int a,b,c,d;
	string s;
	cin>>a>>b>>c>>d;
	cin>>s;
	int t1=0, t2 = 0 , t3 = 0, t4 = 0;
	for (int i=0; i<s.size(); i++){
		if (s[i] == '1'){
			t1+=1;
		}
		if (s[i] == '2'){
			t2+=1;
		}
		if (s[i] == '3'){
			t3+=1;
		}
		if (s[i] == '4'){
			t4+=1;
		}
	}
	cout<<t1*a+t2*b+t3*c+t4*d;
}