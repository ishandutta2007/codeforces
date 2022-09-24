#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string s;
int n, t, p;

int main() {
    cin>>s;
    for (int i=0; i<int(s.size()); i++) {
	if (s[i]=='+') t++;
	else t--;
	p=min(p, t);
    }
    t=-p;
    n=-p;
    for (int i=0; i<int(s.size()); i++) {
	if (s[i]=='+') t++;
	else t--;
	n=max(n, t);
    }
    
    printf("%d\n", n);
    return 0;
}