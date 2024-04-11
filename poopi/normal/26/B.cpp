							/* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;

int n;
char ch[1000010];

int main(){
	gets(ch);
	int len = strlen(ch);
	int res = 0, cnt = 0;
	for(int i = 0; i < len; i++){
		if(ch[i] == '('){
			res++, cnt++;
		}
		if(ch[i] == ')'){
			if(cnt > 0){
				cnt--;
				res++;
			}
		}
	}
	cout << res - cnt << endl;
	return 0;
}