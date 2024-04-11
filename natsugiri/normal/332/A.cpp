#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


int N;
string S;
int main() {
    cin >> N >> S;
    int ans=0;
    for (int i=N; i<int(S.size()); i+=N) {
	int t=0;
	for (int j=i-3; j<i; j++) t += (S[j]=='a' ? 1 : -1);
	if (abs(t)==3) ans++;
    }
    printf("%d\n", ans);
    return 0;
}