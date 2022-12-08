									/* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

long long cnt[100];
char inpp[100010];

int get(char ch){
	if(ch >= 'a' && ch <= 'z')
		return ch - 'a';
	return ch -'0' + 26;
}

int main(){
	scanf("%s", inpp);
	int n = strlen(inpp);
	for(int i = 0; i < n; i++)
		cnt[get(inpp[i])]++;
	long long ret = 0;
	for(int i = 0; i < 36; i++)
		ret += cnt[i] * cnt[i];
	cout << ret << endl;
	return 0;
}