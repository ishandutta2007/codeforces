#include<cstdio>
#include<iostream>
using namespace std;


typedef long long LL;

LL L, R, A;
int main() {
    cin>>L>>R;
    for (int i=0; i<61; i++) {
	if ((1LL<<i)<R-L+1 || (L^R)&(1LL<<i)) A|=1LL<<i;
    }
    cout<<A<<endl;

    return 0;
}