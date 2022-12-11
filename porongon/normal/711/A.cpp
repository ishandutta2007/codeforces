#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n;
char b[1024][8];

int main(){
	scanf("%d",&n);
	bool r=false;
	fore(i,0,n){
		scanf("%s",b[i]);
		if(!r&&b[i][0]=='O'&&b[i][1]=='O'){
			r=true;
			b[i][0]=b[i][1]='+';
		}
		if(!r&&b[i][3]=='O'&&b[i][4]=='O'){
			r=true;
			b[i][3]=b[i][4]='+';
		}
	}
	if(!r)puts("NO");
	else {
		puts("YES");
		fore(i,0,n)puts(b[i]);
	}
	return 0;
}