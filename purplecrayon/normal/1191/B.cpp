#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long LL;

inline int read() {
    int x=0,f=1; char ch=getchar();
    while (!(ch>='0'&&ch<='9')) {if (ch=='-')f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

char a[5],b[5],c[5];

int main() {

	scanf("%s",a); scanf("%s",b); scanf("%s",c);
	if (a[1]==b[1]&&a[1]==c[1]) {
		int x=a[0]-'0',y=b[0]-'0',z=c[0]-'0';
		if (x>y) swap(x,y); if (x>z) swap(x,z);
		if (y>z) swap(y,z);
		if (x==y&&y==z) puts("0");
		else if (y-x==1&&z-y==1) puts("0");
		else if (abs(x-y)<=2||abs(y-z)<=2) puts("1");
		else puts("2");
	} else {
		if (a[1]==b[1]) {
			int x=a[0]-'0',y=b[0]-'0';
			if (abs(x-y)<=2) puts("1");
			else puts("2");
		} else if (a[1]==c[1]) {
			int x=a[0]-'0',y=c[0]-'0';
			if (abs(x-y)<=2) puts("1");
			else puts("2");
		} else if (b[1]==c[1]) {
			int x=c[0]-'0',y=b[0]-'0';
			if (abs(x-y)<=2) puts("1");
			else puts("2");
		} else puts("2");
	}

	return 0;
	
}