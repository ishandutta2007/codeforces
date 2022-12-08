								/* in the name of Allah */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout

int n;
string str;

int main(){
	while(cin >> n){
		cin >> str;
		int dif = -1, bef = 0;
		while(str[bef] != '1')
			bef++;
		string res = "YES";
		for(int p = bef + 1; p < n; p++){
			if(str[p] == '1'){
				if(dif != -1 && dif != p - bef)
					res = "NO";
				dif = p - bef;
				bef = p;
			}
		}
		cout << res << endl;
	}
	return 0;
}