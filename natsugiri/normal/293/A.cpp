#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N;
string S, T;
int c[2][2];
int f, s;

int main() {
    scanf("%d", &N);
    cin>>S>>T;
    for (int i=0; i<int(S.size()); i++) c[S[i]-'0'][T[i]-'0']++;

    f=(c[1][1]+1)/2;
    s=c[1][1]/2;

    if (c[1][1]%2==0) {
	f+=(c[1][0]+1)/2;
    } else {
	f+=c[1][0]/2;
    }

    if ((c[1][1]+c[1][0])%2==0) {
	s+=c[0][1]/2;
    } else {
    	s+=(c[0][1]+1)/2;
    }
    puts(f==s?"Draw":f<s?"Second":"First");
    return 0;
}