#include <iostream>

using namespace std;

int main() {

	int a,b;
	cin >> a >> b;
	int i = 1;
	while(1){
        if(i % 2 ==1){
            if(a - i >= 0){
                a -= i;
            }
            else{
                cout << "Vladik";
                break;
            }

        }
        else{
            if(b - i >= 0){
                b -= i;
            }
            else{
                cout << "Valera";
                break;
            }

        }
        i++;
	}
	return 0;
}