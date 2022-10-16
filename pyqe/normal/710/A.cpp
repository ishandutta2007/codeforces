#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long k,l;
	char ch,ch2;
	
	scanf(" %c %c",&ch,&ch2);
	k=ch-'a';
	l=ch2-'1';
	printf("%lld\n",(long long)(k&&l)+!!k+(k&&l<7)+(l<7)+(k<7&&l<7)+(k<7)+(k<7&&l)+!!l);
}