#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


string S;
int N;

int main() {
    cin>>S; N=S.size();
    vector<int>L, R;
    for (int i=0; i<N; i++) {
	if (S[i]=='l') R.push_back(i+1);
	else L.push_back(i+1);
    }
    for (int i=0; i<int(L.size()); i++) {
	printf("%d\n", L[i]);
    }
    N=R.size();
    for (int i=N-1; i>=0; i--) {
	printf("%d\n", R[i]);
    }

    return 0;
}