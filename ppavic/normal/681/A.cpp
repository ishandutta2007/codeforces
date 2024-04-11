#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int a[1001],b[1001],n;
string c;
bool good = false;

int main(){
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		cin >> c >> a[i] >> b[i];
		if(a[i] >= 2400 && b[i] > a[i]) good = true;
	}
	if(good) printf("YES\n");
	else printf("NO\n");
}