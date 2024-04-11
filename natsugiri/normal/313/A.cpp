#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

LL n, a;

int main() {
    cin>>n;
    a=n;
    if (n<0) {
	n=-n;
	a = max(a, -n/10);
	a = max(a, - n/100*10 - n%10);
    }
    cout<<a<<endl;

    return 0;
}