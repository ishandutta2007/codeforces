#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

typedef long long LL;

string A, B;
int a[2], b[2]; 
int main() {
    cin>>A>>B;
    for (int i=0; i<int(A.size()); i++) a[A[i]=='1']++;
    for (int i=0; i<int(B.size()); i++) b[B[i]=='1']++;
    if (a[1]%2) a[1]++;
    puts(a[1]>=b[1]?"YES":"NO");

    return 0;
}