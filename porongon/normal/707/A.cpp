#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n,m;

int main(){
	cin>>n>>m;
	bool r=true;
	fore(i,0,n)fore(j,0,m){
		char c;
		cin>>c;
		if(c=='C'||c=='M'||c=='Y')r=false;
	}
	puts(r?"#Black&White":"#Color");
	return 0;
}