								/* in the name of Allah */
#include <iostream>
using namespace std;

int main(){
	int a, b, c, d, e, f;
	while(cin >> a >> b >> c >> d >> e >> f){
		if(d == 0)
			cout << "Hermione" << endl;
		else if(c == 0)
			cout << "Ron" << endl;
		else if(b == 0)
			cout << "Hermione" << endl;
		else if(a == 0)
			cout << "Ron" << endl;
		else if(f == 0)
			cout << "Hermione" << endl;
		else if(e == 0)
			cout << "Ron" << endl;
		else cout << (a * c * e < b * d * f ? "Ron" : "Hermione") << endl;
	}
	return 0;
}