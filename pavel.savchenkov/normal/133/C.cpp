#include <cstdio>
#include <cstring>
#include <vector>
#include <bitset>
#include <iostream>
#define pb push_back
using namespace std;
char s[1000];

int rev(int a) {
    bitset <8> b;
	b=a;
	int n=8;
	int st[n];
	st[0]=1;
	for (int i=1;i<n;i++)
		st[i]=st[i-1]*2;
	int res=0;

	for (int i=n-1;i>=0;i--)
		if (b[i]==1) res+=st[n-i-1];
	return res;
}

int main() {
	//freopen("input.txt","r",stdin);
	gets(s);
    for (int i=0;i<(int)strlen(s);i++)
	{   int k=0;
		if (i>0) k=rev(s[i-1]);
		for (int x=0;x<=255;x++)
			if (rev((k-x+256)%256)==s[i]) {printf("%d\n",x);break;}
	}
	
	return 0;
}