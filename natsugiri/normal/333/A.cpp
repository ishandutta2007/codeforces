#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

LL N;
int main() {
    cin>>N;

    LL z=3, M=N;
    for (;M%3==0;) {
	z *= 3;
	M /= 3;
    }

    cout << (N+z-1) / z << endl;
    
    return 0;
}