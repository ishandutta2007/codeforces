#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a,qwer=n;i<qwer;i++)
#define pb push_back
#define snd second
#define fst first
#define mp make_pair
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
int n;
int a[305];
int main(){
	scanf("%d",&n);
	fore(i,0,n) scanf("%d",a+i);
	fore(i,0,n) {
		while(a[i]) {
			putchar('P');
			a[i]--;
			if(a[i]) {
				if(i<n-1) {putchar('R'); putchar('L');}
				else {putchar('L'); putchar('R');}
			}
		}
		if(i<n-1) putchar('R');
	}
	puts("");
}