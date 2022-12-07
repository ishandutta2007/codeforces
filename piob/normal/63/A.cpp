#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n;
string name[110];
string ran[110];

int main(){
	cin >> n;
	FWD(i,0,n)
		cin >> name[i] >> ran[i];
	FWD(i,0,n){
		if(ran[i] == "rat")
			cout << name[i] << endl;
	}
	FWD(i,0,n){
		if(ran[i] == "woman" || ran[i] == "child")
			cout << name[i] << endl;
	}
	FWD(i,0,n){
		if(ran[i] == "man")
			cout << name[i] << endl;
	}
	FWD(i,0,n){
		if(ran[i] == "captain")
			cout << name[i] << endl;
	}
	return 0;
}