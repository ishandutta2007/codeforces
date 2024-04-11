#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


int d[2][1000010]; //[sign][pos]
string S;

int main() {
    cin>>S;
    int N=S.size();
    d[0][1]=1;
    d[1][1]=2;
    for (int i=1; i<N; i++) {
	int b=S[i-1]-'0', x=S[i]-'0';
	if (b==0) {
	    d[0][i+1]=d[0][i]+x;
	    d[1][i+1]=min(d[0][i]+2, d[1][i]+1);
	} else {
	    if (x==0) {
		d[0][i+1]=d[0][i];
	    } else {
		d[0][i+1]=min(d[0][i]+1, d[1][i]);
	    }
	    d[1][i+1]=d[1][i];
	}

    }
    printf("%d\n", d[0][N]);

    return 0;
}