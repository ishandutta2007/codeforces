#include<cstdio>
#include<iostream>
using namespace std;
long long ax,ay,bx,by,cx,cy;
int main(){
	cin>>ax>>ay>>bx>>by>>cx>>cy;
	if((ax-bx)*(ax-bx)+(ay-by)*(ay-by)!=(bx-cx)*(bx-cx)+(by-cy)*(by-cy)) puts("No");
	else if((ax-bx)*(by-cy)==(ay-by)*(bx-cx)) puts("No");
	else puts("Yes");
	return 0;
}