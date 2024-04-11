								/* in the name of Allah */
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout

int f, a, b;
int arr[4];

int main(){
	while(cin >> f){
		for(int i = 1; i <= 3; i++)
			arr[i] = i;
		for(int i = 0; i < 3; i++){
			cin >> a >> b;
			swap(arr[a], arr[b]);
		}
		for(int i = 1; i <= 3; i++)
			if(arr[i] == f)
				cout << i << endl;
	}
	return 0; 
}