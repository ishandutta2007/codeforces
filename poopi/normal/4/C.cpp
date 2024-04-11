							/* in the name of Allah */
#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

map <string, int> mp;
char ch[40];

string tos(int num){
	string ret = "";
	while(num){
		ret = (char)(num % 10 + '0') + ret;
		num /= 10;
	}
	return ret;
}

int main(){
	int n;
	string str, res;
	while(cin >> n){
		mp.clear();
		for(int i = 0; i < n; i++){
			scanf("%s", ch);
			str = ch;
			if(mp.find(str) == mp.end()){
				cout << "OK" << endl;
				mp[str] = 1;
			}
			else{
				str += tos(mp[str]++);
				for(int j = 0; j < str.length(); j++){
					printf("%c", str[j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}