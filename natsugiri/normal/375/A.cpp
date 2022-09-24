#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

string S;
int ans[] = {
    1869,
    1968,
    1689,
    6198,
    1698,
    1986,
    1896};

int main() {
    cin >> S;

    int N=S.size();
    int num[10] = {};
    
    for (int i=0; i<N; i++) num[S[i]-'0']++;
    num[1]--; num[6]--; num[8]--; num[9]--;
    
    int sum = 0, t = 1;
    
    for (int i=0; i<10; i++) {
	for (int j=0; j<num[i]; j++) {
	    sum = (sum*10 + i) % 7;
	    t = t*10%7;
	}
    }
    
    for (int k=0; k<7; k++) {
	if ((t*k+sum) % 7 == 0) {
	    printf("%d", ans[k]);
	    
	    for (int i=0; i<10; i++)
		for (int j=0; j<num[i]; j++)
		    putchar(i+'0');
	    
	    putchar('\n');
	    
	    return 0;
	    
	}
    }
    
    puts("0");
    return 0;
}