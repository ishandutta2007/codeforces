#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, X;

int main() {
    scanf("%d%d", &N, &X);
    if (N==5) printf(">...v\nv.<..\n..^..\n>....\n..^.<\n1 1\n");
    else if (N==3)printf(">vv\n^<.\n^.<\n1 3\n");
    else if (N==100) {
	string s, t;
	s = "v" + string(99, '<');
	for (int i=0; i<32; i++) s[i*2+1] = '.';
	cout << s << endl;

	s = string(98, '>') + "v^";
	for (int i=0; i<32; i++) s[97-i*2] = '.';
	t = "v" + string(98, '<') + "^";
	for (int i=0; i<32; i++) t[i*2+1] = '.';
	for (int i=0; i<49; i++) {
	    if (i<32) s[99] = '.';
	    else s[99]='^';
	    cout << s << endl << t << endl;
	}

	s = string(99, '>') + "^";
	for (int i=0; i<32; i++) s[98-i*2] = '.';
	cout << s << endl;
	cout << "1 1" << endl;
    }
    return 0;
}